#include <iostream>
#define TAM 50

class Constancia{
private:
    std::string nombre;
    std::string carrera;
    int materias_apro;
    float promedio;
public:
    persona(){};
    friend std::ostream & operator<<(std::ostream &O, Constancia &x){
            O<< "----------------------------------------------------------------------------------------------------------------------------------------"<< std::endl 
				<< "						       Constancia de Estudios" << std::endl<< std::endl <<"A QUIEN CORRESPONDA: " << std::endl
            	<< "El que suscribe (Nombre del rector), Rector de la escuela CENTRO UNIVERSITARIO DE CIENCIAS EXACTAS E INGENIERIAS" << std::endl << std::endl
            	<< "      							 HACE CONSTAR" << std::endl << std::endl
            	<< "Que el alumno(a) "<<x.nombre <<" de este plantel esta inscrito(a) en la carrera "<<x.carrera<<" durante el ciclo escolar 2023A"<< std::endl
				<<"comprendido del 15 de enero al 10 de junio del 2023, Con un promedio de "<<x.promedio<<" y un numero de "<<x.materias_apro<<" materias aprobadas"<< std::endl
				<<"A peticion del interesado y para fines legales que le convengan," << std::endl <<"se extiende la presente en la ciudad de Guadalajara, Jalisco a los 10 dias del mes de Marzo del 2023. " << std::endl << std::endl 
              <<"----------------------------------------------------------------------------------------------------------------------------------------"<< std::endl << std::endl; 
			return O;
    }
    friend std::istream & operator>>(std::istream &O, Constancia &x){
            std::cout<<"Ingresa los datos: "<< std::endl;
			std::cout<<"Nombre: "; 
			O.ignore();
            getline(O,x.nombre);
            std::cout<<"Carrera: ";
            getline(O,x.carrera);
            std::cout<<"Materias aprobadas: ";
            O>>x.materias_apro;
            std::cout<<"Promedio: ";
            O>>x.promedio;
            std::cout << std::endl;
            return O;
    }
    bool operator == (std::string x){
		if(nombre == x){
			return true;
		}    	
		else{
			return false;
		}
	}
};

//plantillas
template<class T>
class Cola{
private:
    T datos[TAM];
    int ult;
    bool inserta(T , int);
    bool elimina(int);
    T recupera(int)const;
    int primero()const;
    int ultimo()const;
    void imprime()const;
public:
    Cola():ult(-1){}
    bool vacia()const;
    bool llena()const;
    bool  Queue(T&);
    bool Dequeue();
    T Front()const;
    bool Busqueda(Cola<T>)const;
};

template<class T>
T Cola<T>::Front()const{
    T x=datos[primero()];
    return x;
}

template<class T>
bool Cola<T>::Dequeue(){
    if(vacia()){
        return false;
    }
    else{
        elimina(primero());
    }
    return true;
}

template<class T>
bool Cola<T>::Queue(T& elem){
    if(llena()){
        return false;
    }
    if(vacia()){
        inserta(elem,0);
    }
    else{
        inserta(elem, ultimo()+1);
    }
    return true;
}

template<class T>
void Cola<T>::imprime()const{
    if(!vacia()){
        for(int i=0; i<=ult; i++){
            Constancia x=datos[i];
            std::cout<<x<<std::endl;
        }
    }
}

template<class T>
bool Cola<T>::vacia()const{
    return ult==-1;
}

template<class T>
bool Cola<T>::llena()const{
    return ult==TAM-1;
}

template<class T>
bool Cola<T>::inserta(T elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

template<class T>
bool Cola<T>::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        std::cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

template<class T>
T Cola<T>::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

template<class T>
int Cola<T>::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}

template<class T>
int Cola<T>::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}

template<class T>
bool Cola<T>::Busqueda(Cola<T> x)const{
	Cola<T> copia = x;
	int cont = 1;
	std::string busq;	
	if(copia.vacia()){
		std::cout << "Ingresa una nueva solicitud de constancia ya que no hay ninguna en fila" << std::endl << std::endl;
		return true;
	}
	std::cout << "Ingresa el nombre: ";
	std::cin >> busq;
	while(!copia.vacia()){
		T y = copia.Front();
		if( y == busq){
			std::cout << "Tu constancia es la " << cont << " En la fila de espera" << std::endl << std::endl;
			return true;
		}
		else{
			cont++;
			copia.Dequeue();
		}
	}
	if(copia.vacia()){
		std::cout << "No se encontro ningun nombre " << busq << " en la fila de espera" << std::endl << std::endl;
	}
}


int main()
{
    Cola<Constancia> Cola;
    Constancia Alumno;
    int salir = 0;
    do{
    	int opc;
    	std::cout << "Menu de constancias \n\n" 
    		<< "1) Peticion de constancias \n2) Hacer una constancia (Primera en la fila) \n3) Busqueda de constancia \n4) Salir\n";
    	std::cout << "Ingresa un numero: ";
    	std::cin >> opc;
    	std::cout << std::endl;
    	switch(opc){
    		case 1:
    			std::cin>>Alumno;
    			Cola.Queue(Alumno);
    			break;
    		case 2:
    			Alumno = Cola.Front();
    			std::cout<<Alumno;
    			Cola.Dequeue();
    			break;
    		case 3:
    			Cola.Busqueda(Cola);
    			break;
    		case 4:
    			salir = 1;
    			break;
    		default:
    			std::cout << "Dato invalido \n\n";
    			break;
		}
	}
	while(salir == 0);
    return 0;
}
