//@HEADER
// ************************************************************************
//
//                        Kokkos v. 4.0
//       Copyright (2022) National Technology & Engineering
//               Solutions of Sandia, LLC (NTESS).
//
// Under the terms of Contract DE-NA0003525 with NTESS,
// the U.S. Government retains certain rights in this software.
//
// Part of Kokkos, under the Apache License v2.0 with LLVM Exceptions.
// See https://kokkos.org/LICENSE for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//@HEADER
#include "ctest_common.hpp"

#include <experimental/mdspan>

#include <type_traits>

namespace stdex = std::experimental;

//==============================================================================
// <editor-fold des4c="Test allowed pointer + extents ctors"> {{{1

MDSPAN_STATIC_TEST(
    std::is_constructible<
        stdex::extents<size_t,2, stdex::dynamic_extent>,
        std::array<int,1>
    >::value
);

MDSPAN_STATIC_TEST(
    std::is_constructible<
        stdex::extents<size_t,2, stdex::dynamic_extent>,
        std::array<int,2>
    >::value
);

MDSPAN_STATIC_TEST(
    std::is_constructible<
        stdex::extents<size_t,2, stdex::dynamic_extent>,
        int
    >::value
);

MDSPAN_STATIC_TEST(
    std::is_constructible<
        stdex::extents<size_t,2, stdex::dynamic_extent>,
        int, int64_t
    >::value
);

// TODO @proposal-bug: not sure we really intended this???
MDSPAN_STATIC_TEST(
    std::is_constructible<
        stdex::extents<size_t,2, stdex::dynamic_extent>,
        std::array<float,2>
    >::value
);

MDSPAN_STATIC_TEST(
    std::is_constructible<
        stdex::extents<size_t,2, stdex::dynamic_extent>,
        float, double
    >::value
);

MDSPAN_STATIC_TEST(
    std::is_constructible<
        stdex::mdspan<int, stdex::extents<size_t>>,
        int*
    >::value
);

MDSPAN_STATIC_TEST(
    std::is_constructible<
        stdex::mdspan<int, stdex::extents<size_t,2>>,
        int*
    >::value
);

MDSPAN_STATIC_TEST(
    std::is_constructible<
        stdex::mdspan<int, stdex::extents<size_t,2, stdex::dynamic_extent>>,
        int*, int
    >::value
);

MDSPAN_STATIC_TEST(
    std::is_constructible<
        stdex::mdspan<double, stdex::extents<size_t,stdex::dynamic_extent, 2, stdex::dynamic_extent>>,
        double*, unsigned, int
    >::value
);

MDSPAN_STATIC_TEST(
    std::is_constructible<
        stdex::mdspan<int, stdex::extents<size_t,2, stdex::dynamic_extent>>,
        int*, int, int
    >::value
);

MDSPAN_STATIC_TEST(
    std::is_constructible<
        stdex::mdspan<int, stdex::extents<size_t,stdex::dynamic_extent, 2, stdex::dynamic_extent>>,
        int*, std::array<int,2>
    >::value
);

MDSPAN_STATIC_TEST(
    std::is_constructible<
        stdex::mdspan<int, stdex::extents<size_t,2, stdex::dynamic_extent>>,
        int*, std::array<int,2>
    >::value
);

// </editor-fold> end Test allowed pointer + extents ctors }}}1
//==============================================================================


//==============================================================================
// <editor-fold desc="Test forbidden pointer + extents ctors"> {{{1
MDSPAN_STATIC_TEST(
    !std::is_constructible<
        stdex::extents<size_t,2, stdex::dynamic_extent>,
        std::array<int, 4>
    >::value
);

MDSPAN_STATIC_TEST(
    !std::is_constructible<
        stdex::extents<size_t,2, stdex::dynamic_extent>,
        int, int, int
    >::value
);

MDSPAN_STATIC_TEST(
    !std::is_constructible<
        stdex::mdspan<int, stdex::extents<size_t,2, stdex::dynamic_extent>>,
        int*, std::array<int, 4>
    >::value
);

MDSPAN_STATIC_TEST(
    !std::is_constructible<
        stdex::mdspan<int, stdex::extents<size_t,2, stdex::dynamic_extent>>,
        double*, int
    >::value
);


MDSPAN_STATIC_TEST(
    !std::is_constructible<
        stdex::mdspan<int, stdex::extents<size_t,2, stdex::dynamic_extent>>,
        int*, int, int, int
    >::value
);

MDSPAN_STATIC_TEST(
   !std::is_constructible<
        stdex::mdspan<int, stdex::dextents<size_t,2>, stdex::layout_stride>,
        int*, int, int
   >::value
);

MDSPAN_STATIC_TEST(
   !std::is_constructible<
        stdex::mdspan<int, stdex::dextents<size_t,2>, stdex::layout_stride>,
        int*, std::array<int,2>
   >::value
);

MDSPAN_STATIC_TEST(
   !std::is_constructible<
        stdex::mdspan<int, stdex::dextents<size_t,2>, stdex::layout_stride>,
        int*, stdex::dextents<size_t,2>
   >::value
);

// </editor-fold> end Test forbidden pointer + extents ctors }}}1
//==============================================================================
