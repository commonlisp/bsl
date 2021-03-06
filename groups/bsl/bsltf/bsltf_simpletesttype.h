// bsltf_simpletesttype.h                                             -*-C++-*-
#ifndef INCLUDED_BSLTF_SIMPLETESTTYPE
#define INCLUDED_BSLTF_SIMPLETESTTYPE

#ifndef INCLUDED_BSLS_IDENT
#include <bsls_ident.h>
#endif
BSLS_IDENT("$Id: $")

//@PURPOSE: Provide a non-allocating test class without type traits.
//
//@CLASSES:
//   bsltf::SimpleTestType: non-allocating test class without type traits
//
//@SEE_ALSO: bsltf_templatetestfacility
//
//@DESCRIPTION: This component provides a single, unconstrained in-core
// (value-semantic) attribute class, 'SimpleTestType', that does not take an
// allocator nor define any type traits.  'SimpleTestType' can be used during
// testing as the parameterized type of a class templates to ensure classes
// with the similar properties will function correctly.  Note that this is
// particular valuable when testing a container template that supports
// different types of contained elements.
//
///Attributes
///----------
//..
//  Name                Type         Default
//  ------------------  -----------  -------
//  data                int          0
//..
//: o 'data': representation of the class value
//
///Usage
///-----
// This section illustrates intended use of this component.
//
///Example 1: Printing the Supported Traits
/// - - - - - - - - - - - - - - - - - - - -
// Suppose we wanted to print the supported traits of this test type.
//
// First, we create a function template 'printTypeTraits' with a parameterized
// 'TYPE':
//..
//  template <class TYPE>
//  void printTypeTraits()
//      // Prints the traits of the parameterized 'TYPE' to the console.
//  {
//      if (bslma::UsesBslmaAllocator<TYPE>::value) {
//          printf("Type defines bslma::UsesBslmaAllocator.\n");
//      }
//      else {
//          printf(
//               "Type does not define bslma::UsesBslmaAllocator.\n");
//      }
//
//      if (bslmf::IsBitwiseMoveable<TYPE>::value) {
//          printf("Type defines bslmf::IsBitwiseMoveable.\n");
//      }
//      else {
//          printf("Type does not define bslmf::IsBitwiseMoveable.\n");
//      }
//  }
//..
// Now, we invoke the 'printTypeTraits' function template using
// 'SimpleTestType' as the parameterized 'TYPE':
//..
//  printTypeTraits<SimpleTestType>();
//..
// Finally, we observe the console output:
//..
//  Type does not define bslma::UsesBslmaAllocator.
//  Type does not define bslmf::IsBitwiseMoveable.
//..

#ifndef INCLUDED_BSLSCM_VERSION
#include <bslscm_version.h>
#endif

namespace BloombergLP {
namespace bsltf {

                        // ====================
                        // class SimpleTestType
                        // ====================

class SimpleTestType {
    // This unconstrained (value-semantic) attribute class does not allocate
    // memory and does not define any traits.  See the Attributes section under
    // @DESCRIPTION in the component-level documentation for information on the
    // class attributes.

    // DATA
    int d_data;  // integer class value

  public:

    // CREATORS
    SimpleTestType();
        // Create a 'SimpleTestType' object having the (default) attribute
        // values:
        //..
        //  data() == 0
        //..

    explicit SimpleTestType(int data);
        // Create a 'SimpleTestType' object having the specified 'data'
        // attribute value.

    // SimpleTestType(const SimpleTestType& original) = default;
        // Create a 'SimpleTestType' object having the same value as the
        // specified 'original' object.

    // ~SimpleTestType() = default;
        // Destroy this object.

    // MANIPULATORS
    // SimpleTestType& operator=(const SimpleTestType& rhs) = default;
        // Assign to this object the value of the specified 'rhs' object, and
        // return a reference providing modifiable access to this object.

    void setData(int value);
        // Set the 'data' attribute of this object to the specified 'value'.

    // ACCESSORS
    int data() const;
        // Return the value of the 'data' attribute of this object.
};

// FREE OPERATORS
bool operator==(const SimpleTestType& lhs, const SimpleTestType& rhs);
    // Return 'true' if the specified 'lhs' and 'rhs' objects have the same
    // value, and 'false' otherwise.  Two 'SimpleTestType' objects
    // have the same if their 'data' attributes are the same.

bool operator!=(const SimpleTestType& lhs, const SimpleTestType& rhs);
    // Return 'true' if the specified 'lhs' and 'rhs' objects do not have the
    // same value, and 'false' otherwise.  Two 'SimpleTestType' objects do not
    // have the same value if their 'data' attributes are not the same.

// ===========================================================================
//                  INLINE AND TEMPLATE FUNCTION IMPLEMENTATIONS
// ===========================================================================

                        // --------------------
                        // class SimpleTestType
                        // --------------------

// CREATORS
inline
SimpleTestType::SimpleTestType()
: d_data(0)
{
}

inline
SimpleTestType::SimpleTestType(int data)
: d_data(data)
{
}

// MANIPULATORS
inline
void SimpleTestType::setData(int value)
{
    d_data = value;
}

// ACCESSORS
inline
int SimpleTestType::data() const
{
    return d_data;
}

// FREE OPERATORS
inline
bool operator==(const SimpleTestType& lhs, const SimpleTestType& rhs)
{
    return lhs.data() == rhs.data();
}

inline
bool operator!=(const SimpleTestType& lhs, const SimpleTestType& rhs)
{
    return lhs.data() != rhs.data();
}

}  // close package namespace
}  // close enterprise namespace

#endif

// ----------------------------------------------------------------------------
// Copyright (C) 2013 Bloomberg L.P.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------- END-OF-FILE ----------------------------------
