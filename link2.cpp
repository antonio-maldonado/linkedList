#include<iostream>
#include<cstring>
#include"libs/Node.h"
#include"libs/List.h"
using namespace std;

int main(){
Node *Inicio=CrearNode();
strcpy(Inicio->data.Nombre,"a");
Inicio->data.Matricula=0;
cout<<"ciclo de creacion"<<endl;
Node* ptr=Inicio;
for(int i=0;i<10;i++)
{
TIPO datos={"b",(i+1)*10};
datos.Nombre[0]+=i;

if(!insertNodoLista(ptr,datos))
ptr=ptr->next;
else
exit(EXIT_FAILURE);
/*
Node* dummy=CrearNode();
memcpy(&(dummy->data),&datos,sizeof(TIPO));*/
/*
dummy->data.Nombre[0]='b'+i;
dummy->data.Nombre[1]='\0';
dummy->data.Matricula=(i+1)*10;

dummy->next=ptr->next;
ptr->next=dummy;*/
}
ptr=Inicio;

while(ptr!=NULL)
{
cout<<ptr->data.Nombre[0]<<" ";
//cout<<ptr->data.Nombre[1]<<" ";
cout<<ptr->data.Matricula<<" ";
ptr=ptr->next;
cout<<endl;
}
ptr=Inicio;
int index;
cout<<"Inserta nodo despues de la posicion: : ";
cin>>index;
/*while(ptr!=NULL){
if(contador==index){
cout<<endl<<"El valor encontrado es "<<endl<<"\tNombre: "<<ptr->data.Nombre<<"\tMatricula: "<<ptr->data.Matricula<<endl;
break;
}else{
contador++;
ptr=ptr->next;
}*/


int contador=0;
for(int i=0;i<index;i++){
ptr=ptr->next;
}
TIPO datos={"bb",1000};
insertNodoLista(ptr,datos);

ptr=Inicio;

while(ptr!=NULL)
{
cout<<ptr->data.Nombre[0];
cout<<ptr->data.Nombre[1];
cout<<" "<<ptr->data.Matricula<<" ";
ptr=ptr->next;
cout<<endl;
}
cout<<"Elimina nodo despues de la posicion: ";
cin>>index;


ptr=Inicio;

for(int i=1;i<index;i++){
ptr=ptr->next;
}
eliminaNodoLista(ptr,&datos);

ptr=Inicio;
while(ptr!=NULL)
{
cout<<ptr->data.Nombre[0];
cout<<ptr->data.Nombre[1];
cout<<" "<<ptr->data.Matricula<<" ";
ptr=ptr->next;
cout<<endl;
}
if(contador!=index)
cout<<"No existe nodo en la lista"<<endl;
ptr=Inicio;
cout<<"Ciclo de eliminación"<<endl;
while(ptr->next!=NULL)
{
TIPO datos;
if(eliminaNodoLista(ptr,&datos))
exit(EXIT_FAILURE);
}
EliminaNode(Inicio);

return 0;
}
