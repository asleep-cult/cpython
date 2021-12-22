### What is this repository?
This is an expermental fork of cpython with function prototypes.

### What are function prototypes?
Function prototypes are objects that hold a function's argument and annotation
data, but not their implementation. They are essentially functions with no body.

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
Two new AST nodes were added: `FunctionProto` and `AsyncFunctionProto` \
Three new grammar rules were added: `function_proto`, `function_proto_raw`, and `invalid_function_proto_raw` \
A new object was added to `funcobject.c`: `PyFunctionPrototypeObject` \
A new opcode was added: `MAKE_FUNCTION_PROTOTYPE` \
~~For an in-depth explanation, read through the commit history~~
