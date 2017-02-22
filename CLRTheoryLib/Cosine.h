#pragma once
using namespace System;
namespace Mathematics {
    namespace Circular {
        namespace Functions {
            public value struct Cosine {
                private:
                double c;
                public:
                Cosine( double f );
                Cosine( LinearAlgebra::Vector ^ A , LinearAlgebra::Vector ^ B );
                property double Value {
                    double get() {
                        return this->c;
                    }
                protected: void set( double c ) {
                    this->c = c;
                }
                }
                static operator Cosine ^ (double f);
                static operator double( Cosine ^ c );
                virtual String^ ToString() override;
            };
        }
    }
}