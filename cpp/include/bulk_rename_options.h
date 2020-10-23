//
// Copyright © 2020 Terry Moreland
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// 

#ifndef BULK_RENAME_OPTIONS
#define BULK_RENAME_OPTIONS // NOLINT(clang-diagnostic-unused-macros)

#include <vector>
#include <string_view>
#include <file_order.h>

namespace moreland::file_utilities
{
    using argument_container = std::vector<std::string_view>;

    template <typename FILE_SYSTEM_PARSER>
    class bulk_rename_options final
    {
        file_order m_order{file_order::name_ascending};
        size_t m_starting_number{1};

    public:
        explicit bulk_rename_options(argument_container& arguments)
        {
            int i=0;
            for (auto const count = arguments.size(); i< count; i++) {
                auto& arg = arguments[i];
    
                if (starts_with(arg, "--")) {
                    ++i;
                    arg = arguments[i];
                } else if (starts_with(arg, "-")) {
                    ++i;
                    arg = arguments[i];
                } else
                    continue;


            }
        }
    private:
        [[nodiscard]]
        static constexpr bool starts_with(std::string_view const& source, std::string_view const& value) {
            return source.find(value) == 0;
        }


    };
    
}

#endif
