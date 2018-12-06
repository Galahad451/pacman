#include "colores.h"

Colores::Colores(){}
Colores::~Colores(){}

Color Colores::GetColor(int r,int g,int b,int a){
	Color color = {r,g,b,a};
	return color;
}