#pragma once

#include "core/serialisation/concepts/reader_archtype.hpp"

#include <type_traits>

namespace morpheus::serialisation::concepts
{

template <typename Type>
concept ReadSerialisableFreeStading = requires(ReadSerialiserArchtype s, Type t)
{
    { deserialise(s, t) } -> std::same_as<Type>;
};

template <typename Type>
concept ReadSerialisableInsrusive = requires(ReadSerialiserArchtype s, Type t)
{
    { t.deserialise(s) } -> std::same_as<void>;
};

template <typename Type>
concept ReadSerialisableNative = requires(ReadSerialiserArchtype s, Type t)
{
    { s.reader().template read<Type>() } -> std::same_as<Type>;
};

template <typename Type>
concept ReadSerialisable = ReadSerialisableFreeStading<Type> or
                           ReadSerialisableInsrusive<Type> or 
                           ReadSerialisableNative<Type>;

} // morpheus::serialisation::concepts