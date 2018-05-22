/*******************************************************************************
* Copyright 2017-2018 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#pragma once

#include <memory>
#include <vector>

#include "test_tools.hpp"

namespace ngraph
{
    namespace test
    {
        /// @brief Check if the two floating point numbers are close
        /// @param a First number to compare
        /// @param b Second number to compare
        /// @param mantissa_bits The mantissa width of the underlying number before casting to float
        /// @param tolerance_bits Bit tolerance error
        /// @returns |a - b| < 2 ^ (a.mantissa - mantissa_bits + 1 + tolerance_bits)
        ///
        /// s e e e e e e e e m m m m m m m m m m m m m m m m m m m m m m m
        /// |------------bfloat-----------|
        /// |----------------------------float----------------------------|
        ///
        /// bfloat (s1, e8, m7) has 7 + 1 = 8 bits of mantissa or bit_precision
        /// float (s1, e8, m23) has 23 + 1 = 24 bits of mantissa or bit_precision
        /// Picking 8 as the default mantissa for float_near works for bfloat and float
        bool close_f(float a, float b, int mantissa_bits = 8, int tolerance_bits = 2);

        /// @brief Check if the two floating point vectors are all close
        /// @param a First number to compare
        /// @param b Second number to compare
        /// @param mantissa_bits The mantissa width of the underlying number before casting to float
        /// @param tolerance_bits Bit tolerance error
        /// @returns true iff the two floating point vectors are close
        bool all_close_f(const std::vector<float>& a,
                         const std::vector<float>& b,
                         int mantissa_bits = 8,
                         int tolerance_bits = 2);

        bool close_g(float a, float b, int mantissa_bits = 8, int tolerance_bits = 2);

        bool all_close_g(const std::vector<float>& a,
                         const std::vector<float>& b,
                         int mantissa_bits = 8,
                         int tolerance_bits = 2);
    }
}
