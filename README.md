# Usage
- 
- Manually
```powershell

./make_single_header.py ./include/mdspan/mdspan.hpp > ./mdspan.hpp

```
- Or just `wget https://raw.githubusercontent.com/kokkos/mdspan/refs/heads/single-header/mdspan.hpp`
Caveats
-------

This implementation is fully conforming with the version of `mdspan` voted into the C++23 draft standard in July 2022.
When not in C++23 mode the implementation deviates from the proposal as follows:

### C++20
- implements `operator()` not `operator[]`
  - note you can control which operator is available with defining `MDSPAN_USE_BRACKET_OPERATOR=[0,1]` and `MDSPAN_USE_PAREN_OPERATOR=[0,1]` irrespective of whether multi dimensional subscript support is detected.

### C++17
- mdspan has a default constructor even in cases where it shouldn't (i.e. all static extents, and default constructible mapping/accessor)
- the conditional explicit markup is missing, making certain constructors implicit
  - most notably you can implicitly convert from dynamic extent to static extent, which you can't in C++20 mode
- there is a constraint on `layout_left::mapping::stride()`, `layout_right::mapping::stride()` and `layout_stride::mapping::stride()` that `extents_type::rank() > 0` is `true`, which is not implemented in C++17 or C++14.

### C++14
- deduction guides don't exist
- submdspan (P2630) is not available - an earlier variant of submdspan is available up to release 0.5 in C++14 mode
- benchmarks are not available (they need submdspan)



Acknowledgements
===
This work was undertaken as part of the [Kokkos project](https://github.com/kokkos/kokkos) at Sandia National Laboratories.  Sandia National Laboratories is a multimission laboratory managed and operated by National Technology & Engineering Solutions of Sandia, LLC, a wholly owned subsidary of Honeywell International Inc., for the U. S. Department of Energy's National Nuclear Security Administration under contract DE-NA0003525