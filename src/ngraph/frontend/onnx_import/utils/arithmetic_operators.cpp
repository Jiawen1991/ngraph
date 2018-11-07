//*****************************************************************************
// Copyright 2017-2018 Intel Corporation
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
//*****************************************************************************

#include "arithmetic_operators.hpp"
#include "ngraph/node_vector.hpp"
#include "ngraph/op/add.hpp"
#include "ngraph/op/multiply.hpp"
#include "utils/broadcasting.hpp"

namespace ngraph
{
    namespace onnx_import
    {
        std::shared_ptr<ngraph::Node> operator+(const std::shared_ptr<ngraph::Node>& lhs,
                                                const std::shared_ptr<ngraph::Node>& rhs)
        {
            auto args = numpy_style_broadcast_for_binary_operation(lhs, rhs);
            return {std::make_shared<ngraph::op::Add>(args.at(0), args.at(1))};
        }

        std::shared_ptr<ngraph::Node> operator*(const std::shared_ptr<ngraph::Node>& lhs,
                                                const std::shared_ptr<ngraph::Node>& rhs)
        {
            auto args = numpy_style_broadcast_for_binary_operation(lhs, rhs);
            return {std::make_shared<ngraph::op::Multiply>(args.at(0), args.at(1))};
        }
    }
}