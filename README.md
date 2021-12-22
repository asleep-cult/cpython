### What is this repository?
This is an expermental fork of cpython with function prototypes. This fork also
adds an alternative lambda syntax with support for annotations and prototyping.

### What are function prototypes?
Function prototypes are objects that hold a function's argument and annotation
data, but not their implementation. They are essentially functions with no body.

### How can you annotate lambdas?
Due to parsing ambiguities, you can only annotate lambdas when the argument list
is patenthesized.

```py
>>> f = lambda (x: int, y: int) -> int: x + y
>>> f(5, 5)
10
>>> f.__annotations__
{'x': <class 'int'>, 'y': <class 'int'>, 'return': <class 'int'>}
```

### How do you use them?
```py
   >>> async def x(a: int, c: str = 0, /, d: dict = {}, e: list = [], *, f: set, g: 10 = 10) -> None
   ...
   >>> x.__async__
   True
   >>>
   >>> x.__defaults__
   (0, {}, [])
   >>>
   >>> x.__kwdefaults__
   {'g': 10}
   >>>
   >>> x.__annotations__
   {'d': <class 'dict'>,
    'e': <class 'list'>,
    'a': <class 'int'>,
    'c': <class 'str'>,
    'f': <class 'set'>,
    'g': 10,
    'return': None}
   >>>
   >>> x.__posonlyargnames__
   ('a', 'c')
   >>>
   >>> x.__argnames__
   ('d', 'e')
   >>>
   >>> x.__kwonlyargnames__
   ('f', 'g')
   >>>
   >>> x.__qualname__
   '<module>.x'
   >>>
   >>> x.__name__
   'x'
```

Alternatively, you can use an lambda prototype.
```py
>>> x = lambda (a: int, c: str = 0, /, d: dict = {}, *, e: set = set()) -> list
>>>
>>> x.__async__
False
>>>
>>> x.__defaults__
(0, {})
>>>
>>> x.__kwdefaults__
{'e': set()}
>>>
>>> x.__annotations__
{'d': <class 'dict'>,
 'a': <class 'int'>,
 'c': <class 'str'>,
 'e': <class 'set'>,
 'return': <class 'list'>}
>>>
>>> x.__posonlyargnames__
('a', 'c')
>>>
>>> x.__argnames__
('d',)
>>>
>>> x.__kwonlyargnames__
('e',)
>>>
>>> x.__qualname__
'<module>.<lambda>'
>>>
>>> x.__name__
'<lambda>'
```

Note: You cannot create an lambda prototype without parenthesizing the argument list.
      `lambda` will fail, `lambda ()` will not.

### Can you use decorators?
Function prototypes allow you to use decorators in the same fashion that you would with regular functions.

```py
>>> def decorate(prototype):
...     print(f'A really cool prototype: {prototype}')
...     return 'Or maybe it was a string. ;)'
...
>>> @decorate
... def i_am_not_a_string()
...
A really cool prototype: <function-prototype <module>.i_am_not_a_string at 0x00000211AECC14F0>
>>> i_am_not_a_string
'Or maybe it was a string. ;)'
```

#### What if you just forgot the colon?
The parser now raises a special error when it finds a function prototype that is followed by a block.

```py
>>> def x()
...     pass
  File "<stdin>", line 2
    pass
IndentationError: unexpected indent after function prototype on line 1, parhaps you forgot a ":"?
>>>
>>> def x() pass
  File "<stdin>", line 1
    def x() pass
            ^^^^
SyntaxError: expected newline after function prototype on line 4, perhaps you forgot a ":"?
```

### How is this implemented?
Three new AST nodes were added: `FunctionProto`, `AsyncFunctionProto`, and `LambdaProto` \
Four new grammar rules were added: `function_proto`, `function_proto_raw`, `invalid_function_proto_raw`, and `lambdaproto` \
A new object was added to `funcobject.c`: `PyFunctionPrototypeObject` \
A new opcode was added: `MAKE_FUNCTION_PROTOTYPE`
