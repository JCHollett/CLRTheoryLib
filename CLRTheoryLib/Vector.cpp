#include "Stdafx.h"
namespace LinearAlgebra {
    Vector::Vector( ARRAY( double ) ^ elements ) {
        if ( elements->Length > (int)Dimension::R4 || elements->Length < (int)Dimension::R1 ) {
            throw NEW System::ArgumentOutOfRangeException( "Dimensional NSpace Exception" );
        } else {
            this->Dim = (Dimension)(elements->Length);
            this->N = elements;
        }
    }

    Vector::Vector( Dimension d ) {
        if ( d > Dimension::R4 || d < Dimension::R1 ) {
            throw NEW System::ArgumentOutOfRangeException( "Dimensional NSpace Exception" );
        } else {
            this->Dim = d;
            this->N = NEW ARRAY( double )(this->NSpace);
        }
    }

    Vector::operator UnityEngine::Vector2( Vector v ) {
        if ( v.NSpace == 2 )
            return UnityEngine::Vector2( v[0] , v[1] );
        else throw NEW System::InvalidCastException( String::Format( "Invalid cast Vector{0}D to Vector{1}" , v.NSpace , 1 ) );
    }

    Vector::operator UnityEngine::Vector3( Vector v ) {
        if ( v.NSpace == 3 )
            return UnityEngine::Vector3( v[0] , v[1] , v[2] );
        else throw NEW System::InvalidCastException( String::Format( "Invalid cast Vector{0}D to Vector{1}" , v.NSpace , 2 ) );
    }

    Vector::operator UnityEngine::Vector4( Vector v ) {
        if ( v.NSpace == 4 )
            return UnityEngine::Vector4( v[0] , v[1] , v[2] , v[3] );
        else throw NEW System::InvalidCastException( String::Format( "Invalid cast Vector{0}D to Vector{1}" , v.NSpace , 3 ) );
    }

    Vector::operator double( Vector^ A ) {
        if ( A->magnitude == 0 ) {
            double len = 0.0f;
            for ( int i = 0; i < A->NSpace; ++i ) {
                len += A[i] * A[i];
            }
            return (A->magnitude = sqrt( len ));
        } else
            return A->magnitude;
    }

    double Vector::operator*( Vector ^ A , Vector^ B ) {
        if ( A->NSpace == B->NSpace ) {
            double DOT = 0;
            for ( int i = 0; i < A->NSpace; ++i ) {
                DOT += A->N[i] * B->N[i];
            }
            return DOT;
        } else {
            throw NEW System::ArithmeticException( "Vector NSpace mismatch" );
        }
    }
    Vector^ Vector::operator*( Vector^ A , double B ) {
        if ( B == 1.0f ) {
            Vector^ V = NEW Vector( A->Dim );
            for ( int i = 0; i < V->NSpace; ++i ) {
                V->N[i] = A->N[i] * B;
            }
            return V;
        } else {
            return A;
        }
    }
    Vector^ Vector::operator*( double B , Vector^ A ) {
        if ( B == 1.0f ) {
            Vector^ V = NEW Vector( A->Dim );
            for ( int i = 0; i < V->NSpace; ++i ) {
                V->N[i] = A->N[i] * B;
            }
            return V;
        } else {
            return A;
        }
    }
    Vector^ Vector::operator+( Vector^ A , Vector^ B ) {
        if ( A->NSpace == B->NSpace ) {
            Vector^ V = NEW Vector( A->Dim );
            for ( int i = 0; i < V->NSpace; ++i ) {
                V->N[i] = A->N[i] + B->N[i];
            }
            return V;
        } else {
            throw NEW System::ArithmeticException( "Vector NSpace mismatch" );
        }
    }
    Vector^ Vector::operator-( Vector^ A , Vector^ B ) {
        if ( A->NSpace == B->NSpace ) {
            Vector^ V = NEW Vector( A->Dim );
            for ( int i = 0; i < V->NSpace; ++i ) {
                V->N[i] = A->N[i] - B->N[i];
            }
            return V;
        } else {
            throw NEW System::ArithmeticException( "Vector NSpace mismatch" );
        }
    }
    String^ Vector::ToString() {
        return String::Format( "Vector{0}D<{1}>->({2:F})" , this->NSpace , String::Join( "," , Array::ConvertAll( (this->N) , DtoStr ) ) , (double)(% *this) );
    }
}