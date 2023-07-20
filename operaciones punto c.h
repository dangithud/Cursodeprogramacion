#ifndef OPERACIONES_PUNTO_C_H_INCLUDED
#define OPERACIONES_PUNTO_C_H_INCLUDED
int sumar(int op1, int op2){
    return op1+op2;
}
int restar(int op1, int op2){
    return op1-op2;
}
int multiplicar(int op1, int op2){
    return op1*op2;
}
float dividir(int op1, int op2){
    if (op2 == 0){
        return 0;
    }
    else{
        return (float)op1/op2;
    }


}
#endif // OPERACIONES_PUNTO_C_H_INCLUDED
