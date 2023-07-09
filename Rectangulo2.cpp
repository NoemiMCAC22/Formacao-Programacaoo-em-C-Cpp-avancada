#include <iostream>

using namespace std;

class Retangulo {
    public:
	    void Display();
        void Display_area();
        void Display_perimetro();
        void Draw();
        void SetValues( double a, double c );

    private:
	    double comp;   // Length of a box
    	double altura; // Height of a box
};

void Retangulo::Display() {
    cout << "O rectangulo de " << comp << " X " << altura << endl;
}

void Retangulo::Display_area() {
    double area = altura * comp;

    cout << "O rectangulo de " << comp << " X " << altura << " area= " << area << endl;
}

void Retangulo::Display_perimetro() {
    double perimetro = 2 * ( altura + comp );

    cout << "O rectangulo de " << comp << " X " << altura << " perimetro= " << perimetro << endl;
}

void Retangulo::Draw() {
    for( int i = 0; i < altura; i++ ) {
        for( int j = 0; j < comp; j++ )
            cout << "*";
        cout << endl;
    }
}

void Retangulo::SetValues( double a, double c ) {
    altura = a;
    comp = c;
}

int main() {
	Retangulo Box1;	   // Declara Box1 do tipo Retangulo 
	Retangulo Box2;    // Declara Box2 do tipo Retangulo
	
    Box1.SetValues( 5.0, 6.0 );
    Box2.SetValues( 10.0, 12.0 );

    Box1.Display();
    Box2.Display();
    Box1.Display_area();
    Box2.Display_area();

    Box1.Display_perimetro();
    Box1.Draw();
    	
	return 0;
}