/**
 * @file operations_enum.hpp
 * @brief A type-safe enumeration that enumerates every operation claricpp handles
 */
#ifndef __OPS_OPERATIONS_ENUM_HPP__
#define __OPS_OPERATIONS_ENUM_HPP__

/** A namespace used for the ops directory */
namespace Ops {
    /** A type-safe enumeration that enumerates every operation claricpp handles
     *  @todo Should this be Reverse?
     */
    enum class Operation {
        __add__,
        __radd__,
        __div__,
        __rdiv__,
        __truediv__,
        __rtruediv__,
        __floordiv__,
        __rfloordiv__,
        __mul__,
        __rmul__,
        __sub__,
        __rsub__,
        __pow__,
        __rpow__,
        __mod__,
        __rmod__,
        __divmod__,
        __rdivmod__,
        SDiv,
        SMod,
        __neg__,
        __pos__,
        __abs__,
        __or__,
        __ror__,
        __and__,
        __rand__,
        __xor__,
        __rxor__,
        __eq__,
        __ne__,
        __ge__,
        __le__,
        __gt__,
        __lt__,
        __invert__,
        __lshift__,
        __rlshift__,
        __rshift__,
        __rrshift__,
        union_,
        intersection,
        widen,
        SGE,
        SLE,
        SGT,
        SLT,
        UGE,
        ULE,
        UGT,
        ULT,
        RotateLeft,
        RotateRight,
        LShR,
        Reverse,
        And,
        Or,
        Not,
        Concat,
        Extract,
        SignExt,
        ZeroExt,
        BoolV,
        BVV,
        FPV,
        StringV,
        BoolS,
        BVS,
        FPS,
        StringS,
        TopStridedInterval,
        StridedInterval,
        ValueSet,
        AbstractLocation,
        If,
        fpLT,
        fpLEQ,
        fpGT,
        fpGEQ,
        fpEQ,
        fpToFP,
        fpToIEEEBV,
        fpFP,
        fpToSBV,
        fpToUBV,
        fpNeg,
        fpSub,
        fpAdd,
        fpMul,
        fpDiv,
        fpAbs,
        StrSubstr,
        StrReplace,
        StrConcat,
        StrLen,
        StrContains,
        StrPrefixOf,
        StrSuffixOf,
        StrIndexOf,
        StrToInt,
        StrIsDigit,
        IntToStr,
        Identical,
        Reversed
    };
} // namespace Ops

#endif
