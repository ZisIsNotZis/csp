from ctypes import CDLL
from numpy.ctypeslib import as_ctypes_type

class DLL:
    __slots__ = ('f', 'a')
    def __init__(s, so, f, arg):
        s.f = getattr(CDLL(so), f)
        arg = tuple(as_ctypes_type(i) for i in arg)
        s.f.restype = arg[0]
        s.a = arg[1:]
    def __call__(s, *arg):
        return s.f(*(i(j.ctypes.data if hasattr(j,'ctypes') else j) for i,j in zip(s.a,arg)))
