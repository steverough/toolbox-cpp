// The Reactive C++ Toolbox.
// Copyright (C) 2013-2019 Swirly Cloud Limited
// Copyright (C) 2021 Reactive Markets Limited
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Exception.hpp"

#include <boost/test/unit_test.hpp>

using namespace toolbox;

BOOST_AUTO_TEST_SUITE(ExceptionSuite)

BOOST_AUTO_TEST_CASE(ExceptionCase)
{
    const auto ec = std::make_error_code(std::errc::invalid_argument);
    const Exception e{ec, "cannot send message"};
    BOOST_TEST(e.what() == "cannot send message");
    BOOST_TEST(e.code() == ec);
    std::stringstream ss;
    ss << put_with_code(e);
    BOOST_TEST(ss.str() == "cannot send message (22)");
}

BOOST_AUTO_TEST_CASE(ExceptionToJsonCase)
{
    const auto ec = std::make_error_code(std::errc::invalid_argument);
    const Exception e{ec, "cannot send message"};

    std::stringstream ss;
    ss << put_as_json(e);

    BOOST_TEST(ss.str() == //
               "{\"code\":22"
               ",\"message\":\"cannot send message\""
               "}");
}

BOOST_AUTO_TEST_SUITE_END()
