#include "Stdafx.h"

using namespace Mathematics::Circular;
Functions::Cosine Mathematics::Function::CosFunc( Radian p ) {
	return Functions::Cosine( cos( p.Value ) );
}

Functions::Sine Mathematics::Function::SinFunc( Radian p ) {
	return Functions::Sine( sin( p.Value ) );
}

Radian Mathematics::Function::ACosFunc( Functions::Cosine t ) {
	return Radian( acos( t.Value ) );
}

Radian Mathematics::Function::ASinFunc( Functions::Sine t ) {
	return Radian( asin( t.Value ) );
}