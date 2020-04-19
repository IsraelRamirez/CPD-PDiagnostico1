#include <iostream>
#include <string>

/**
 * 
 * @param codigo Es el código ingresado por el usuario a convertir.
 * @return Devuelve el código convertido.
 */

/**
 * Convierte un código ingresado por el usuario al siguiente formato: 
 * Cuenta las letras consecutivas dentro del código
 * Luego guarda la letra y sucesivamente la cantidad de letras que componen sucesivamente esa letra
 * Ej: Código -> xxxaaaammmmm; Al convertirlo quedaría -> x3a4m5
 */
std::string conversorDeCodigo(std::string codigo){
    
    //Se crea una variable de almacenamiento para el nuevo código.
    std::string codigoConvertido = "";
    
    //Se selecciona la primera letra del código.
    char letra = codigo[0];
    
    //Se inicializa el contrador de letra, cuenta cuantas veces se repite la letra consecutivamente.
    int contadorLetra = 0;
    
    //El ciclo "for" recorre el código original
    for(int i = 0; i < codigo.length() + 1 ; i++){
        //Verifica si la letra que se lee es consecutiva, de no serlo entra a la condición.
        if(letra != codigo[i]){
            
            //Guarda en la variable de "codigoConvertido" la letra en análisis y cuantas veces se repitió consecutivamente.
            codigoConvertido += letra + std::to_string(contadorLetra);
            
            //Reinicia el contador en 1, debido a que se cunta la primera letra.
            contadorLetra = 1;
            
            //Guarda la primera letra de la secuencia.
            letra = codigo[i];
        }
        
        //Si la letra que se lee es consecutiva, si lo es entra a la condición y suma "1" al contador de letras consecutivas.
        else{
            contadorLetra++;
        }
        
    }
    
    //Una vez convertido el código devuelve el valor del código final.
    return codigoConvertido;
}

/**
 * 
 * @param argc Número de argumentos ingresados por el cliente.
 * @param argv Arreglo argumentos ingresados por el cliente.
 * @return Retorna el código simplificado, del código ingresado por el cliente
 */
int main(int argc, char** argv){
    //Detecta si el usuario ha ingresado una palabra como código.
    if(argc > 1){
        
        //Muestra al usuario el código ingresado.
        std::cout << std::endl << "Código Ingresado: " << argv[1] << std::endl;
        
        //Entrega el nuevo código convertido al usuario mostrandolo por pantalla.
        std::cout << std::endl << "Nuevo código convertido: " << conversorDeCodigo(argv[1]) << std::endl;
    }
    //Detecta si el usuario no ha ingresado una palabra como código.
    else{
        std::cout<< std::endl << "Ha ocurrido un error: Debe ingresar una palabra como código." << std::endl;
        return 1;
    }
}
