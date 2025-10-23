//
//  test.cpp
//
//  Tests to prove your code works.
//  You SHOULD modify this file.
//
//  Copyright 2019 David Kopec
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation files
//  (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge,
//  publish, distribute, sublicense, and/or sell copies of the Software,
//  and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice
//  shall be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
//  OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>
#define SECTION(name) DOCTEST_SUBCASE(name)
#undef TEST_CASE
#define TEST_CASE(name, tags) DOCTEST_TEST_CASE(tags " " name)
using doctest::Approx;

#include <string>

#include "Queue.h"
#include "Stack.h"

using namespace std;
using namespace csi281;

TEST_CASE("Queue Tests", "[queue]")
{
    SECTION("Queue w/ int tests")
    {
        Queue<int> q1 = Queue<int>();

        // Checking Push and Peek
        q1.push(34);
        q1.push(54);
        q1.push(74);
        auto value = q1.peek();
        CHECK(value == 34);

        // Check Removing
        q1.remove(34);
        q1.remove(54);
        q1.remove(74);
        CHECK(q1.getCount() == 0);

        // Checking Pop
        q1.push(67);
        q1.push(89);
        CHECK(q1.pop() == 89);
    }

    SECTION("Queue w/ string tests")
    {
        Queue<string> q2 = Queue<string>();

        // Checking Push and Peek
        q2.push("fish");
        q2.push("dog");
        q2.push("cat");
        auto value = q2.peek();
        CHECK(value == "fish");

        // Check Removing
        q2.remove("fish");
        q2.remove("dog");
        q2.remove("cat");
        CHECK(q2.getCount() == 0);

        // Checking Pop
        q2.push("moose");
        q2.push("horse");
        CHECK(q2.pop() == "horse");
    }
}

TEST_CASE("Stack Tests", "[stack]")
{
    SECTION("Stack w/ int tests")
    {
        Stack<int> s1 = Stack<int>();
        
        // Checking Push and Peek
        s1.push(34);
        s1.push(54);
        s1.push(74);
        auto value = s1.peek();
        CHECK(value == 74);

        // Check Removing
        s1.remove(34);
        s1.remove(54);
        s1.remove(74);
        CHECK(s1.getCount() == 0);

        // Checking Pop
        s1.push(67);
        s1.push(89);
        CHECK(s1.pop() == 67);
    }

    SECTION("Stack w/ string tests")
    {
        Stack<string> s2 = Stack<string>();
        
        // Checking Push and Peek
        s2.push("fish");
        s2.push("dog");
        s2.push("cat");
        auto value = s2.peek();
        CHECK(value == "cat");

        // Check Removing
        s2.remove("fish");
        s2.remove("dog");
        s2.remove("cat");
        CHECK(s2.getCount() == 0);

        // Checking Pop
        s2.push("moose");
        s2.push("horse");
        CHECK(s2.pop() == "moose");
    }
}
