from typing import Any

def _if(*args, __eq: bool=True) -> Any:
    bool_exper = ''
    if __eq:
        bool_exper = " == ".join(map(str, args))
        
    elif not __eq:
        bool_exper = " != ".join(map(str, args))

    print(bool_exper)
    print(eval(bool_exper))

_if(1, 2, 3)
