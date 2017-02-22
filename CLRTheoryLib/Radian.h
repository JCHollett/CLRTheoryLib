#pragma once
using namespace System;
using namespace LinearAlgebra;
namespace Mathematics {
    namespace Circular {
        public value struct Radian {
            private:
            double rads;
            public:
            Radian( double r );
            property double Value {
                double get() {
                    return this->rads;
                }
            private: void set( double f ) {
                this->rads = f;
            }
            };
            static operator double( Radian ^ r );
            static operator Radian( double r );
            static explicit operator Radian( Degree d );
            virtual String^ ToString() override;
        };
    }
}