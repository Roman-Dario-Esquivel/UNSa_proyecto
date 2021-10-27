#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#define TMAX 31 //define territorio maximo

typedef char T_cadena[TMAX];// dedine la structura de una cadena


//T_producto
typedef struct
{
	
	int codigo;
	T_cadena nombre_producto;
	float precio;
	T_cadena rubro;
	int stock;
	
}T_producto;//producto estructura

//T_lista_producto
typedef T_producto T_lista_producto[TMAX];  //LISTA DE DE PRODUCTOS

//T_lista
typedef struct
{
	
	T_lista_producto lista;
	int can_max;
	
}T_lista; //LISTA de productos en un registro, ***

//T_combo
typedef struct
{
	
	T_lista T_combo;//(1, 2, 6)=c1
	T_cadena nombre_combo;//c1=Carpinteria
	int cant_elem;//elementos de un combo
	int stock;
	
}T_combo;
//T_lista_de_combo carga_lis_com();// tienda.lista_combos.=carga_lis_com();

/*


*/

//  T_stock tienda;
//tienda.lista_combos=crear_combos()






typedef T_combo T_lista_combo[TMAX];//c1,c2,c3
//T_lista_de_combos
typedef struct
{
	
	T_lista_combo lista;
	int cant_de_combos;
	
}T_lista_de_combos; // regstro de lista des combos

//T_stock
typedef struct
{
	
	T_lista lis_uni;
	T_lista_de_combos lista_combos;
	
}T_stock;//registro T_stock

//CLIENTE cliente_carrito
typedef struct
{
	
	T_lista lista_comprado_uni;//listado unitario de productos comprados en registro
	T_lista_de_combos comb_comprado; // listado  de combos comprados  en un registro
	float importe;
}cliente_carrito;//registro cliente

//MODULOS CARGAR STOCK PRODUCTOS
void repositar_ini(T_stock* tienda);

//MODULO CREAR COMBO
void mostrar_productos(T_stock tienda);
void crear_combos(T_stock* tienda);
	
// MODULO PARA ELIMINAR PRODUCTO DEL CARRITO
void borrar_productto_carrito(cliente_carrito *cliente);
//MODULO COMPRAR COMBO
void Comprar(cliente_carrito* cliente, T_stock* tienda);
//MODULOS MENU
char menuAd();
char menuPrn();
char menuAdm1();
void menuadmn3(T_stock* tienda,cliente_carrito* cliente);

//MODULO leeCad
void leeCad(char cadena[], int tam);

//MODULO descontinuar producto unitario por Codigos
void descontinuar_producto(T_stock *tienda);
//Modulo Compra de productos unitario
void comprar_productos_unitario(T_stock *tienda, cliente_carrito *cliente);
//Modulo Mostrar Compra e importe
void mostrar_compra(cliente_carrito cliente);
//MODULO ELIMINAR PRODUCTO DE UN COMBO
void eliminar_pcombo(cliente_carrito* cliente, T_stock* tienda);
//MAIN
int main()
{
  


	cliente_carrito cliente;
  
	T_stock tienda;
	
	
	char opc;
	char opc1;
	
	do{
		opc=menuAd();
		switch (opc)
		{
		case 'S':repositar_ini(&tienda); break;//Cargar Productos
		
		case 'C': crear_combos(&tienda); break; //Cargar Combos
		
		};
		
	}while(opc!='E');
	
	//Segundo menu//
	//Menu Principal De Compras//
	//Sub Menu de Reposito y Salidas//
	
	
	do{
		opc1=menuPrn();
		//__fpurge(stdin);
		switch (opc1)
		{
		case 'I': comprar_productos_unitario(&tienda, &cliente); break;
		
		case 'C':Comprar(&cliente,&tienda); break; 
		
		case 'D':borrar_productto_carrito(&cliente); break;
		
		case 'L': break; 
		
		case 'A': menuadmn3(&tienda,&cliente); break;
		}
	}while(opc1!='Z');


  system("cls");

	 mostrar_compra(cliente);
	printf("Hasta luego, vuelva pronto!");
  printf("\n\ncombo comprado %s ",cliente.comb_comprado.lista[1].nombre_combo);
	
  

	return 0;
}//FIN DE MAIN
//ELIMINAR PRODUCTO DE UN COMBO

//Modulo Mostrar Combo Lista
void mostrar_combos1(T_lista_producto lista)
{
	int i,j;
	
	//Mostrar combos
	
	
		printf("Nombre: %s		Rubro: %s\n",lista->nombre_producto,lista->rubro);
		printf("Precio: %f		Codigo: %d\n",lista->precio,lista->codigo);
		printf("Stock: %d\n\n",lista->stock);
		
	
}
//Modulo actualizar Stock
void actualizar_stock(T_lista* lis_uni, T_combo* combo_comprado)
{
	int i, j;
	
	for(i=1;i<=combo_comprado->cant_elem;i++)
		for(j=1;j<=lis_uni->can_max;j++)
		if(combo_comprado->T_combo.lista[i].codigo==lis_uni->lista[j].codigo)
			lis_uni->lista[j].stock=lis_uni->lista[j].stock-combo_comprado->T_combo.lista[i].stock;
}
//Modulo buscar_combo
int buscar_nomcombo(T_lista_combo lista,int n, T_cadena nom_combo)
{
	int i=1;
	
	while(i<=n && strcmp(lista[i].nombre_combo,"nomb_combo")!=0)
		i++;
	
	if(i<=n)
		return i;
	else
		return -1;
}

//BUSCAR CODIGO
int buscar_codigo(T_lista_producto lista, int n, int eliminar_cod)
{
	int i=1;
	
	while(i<=n && lista->codigo != eliminar_cod)
		i++;
	
	if(i<=n)
		return i;
	else
		return -1;
}
//Eliminar producto dlel combo_comprado
void eliminar_productocomb(T_lista_producto lista, int* t , int pos)
{
	int i, N;
	
	N=*t;
	for(i=pos; i<=N; i++)
		lista[i]=lista[i+1];
	*t=N-1;
}
//Modulo Comprar Combo
void eliminar_pcombo(cliente_carrito* cliente, T_stock* tienda)
{
  printf("AKSHAKSGKAGSKASASKAGSAGKA:D");
	int i;
	int j;
	int pos;
	int pos2;
	T_cadena nom_combo;
	int eliminar_cod;
	
  for(i=1;i<=cliente->comb_comprado.cant_de_combos;i++)
  for(j=1;j<=cliente->comb_comprado.lista[i].cant_elem;j++)
	mostrar_combos1(&cliente->comb_comprado.lista[i].T_combo.lista[j]);
	
	
	printf("Ingrese el nombre del Combo al cual desea ingresar:");
	leeCad(nom_combo,TMAX);
	
	pos=buscar_nomcombo(cliente->comb_comprado.lista,cliente->comb_comprado.cant_de_combos, nom_combo);
	
  
  
	mostrar_combos1(cliente->comb_comprado.lista[pos].T_combo.lista);
	
	printf("ingrese el codigo del producto que desea eliminar: ");
	scanf("%d",&eliminar_cod);
	
	pos2=buscar_codigo(cliente->comb_comprado.lista[pos].T_combo.lista, cliente->comb_comprado.lista[pos].cant_elem,eliminar_cod);
	
	tienda->lis_uni.lista[pos].stock=tienda->lis_uni.lista[pos].stock+cliente->comb_comprado.lista[pos].T_combo.lista[pos2].stock;
	
	eliminar_productocomb(cliente->comb_comprado.lista[pos].T_combo.lista, &cliente->comb_comprado.lista[pos].cant_elem,pos2);
	
	
}



//COMPRA DE COMBOS
//Mostrar Combo Productos
void mostrar_datos(T_producto lista, int n)
{
	printf("Nombre: %s		Rubro: %s\n",lista.nombre_producto,lista.rubro);
	printf("Precio: %2.2f		Codigo: %d\n",lista.precio,lista.codigo);
	printf("Stock: %d\n\n",lista.stock);
	
}
//Modulo Mostrar Combo Lista
void mostrar_combos(T_stock tienda)
{
	int i,j;
	
	//Mostrar combos
	for(i=1;i<=tienda.lista_combos.cant_de_combos;i++)
	{
		//Se muestr: Nombre, Precio, del Combo
    printf("         Combo #%d\n",i);
    printf("      Nombre del Combo %s,  Precio del Combo %d\n",tienda.lista_combos.lista[i].nombre_combo,tienda.lista_combos.lista[i].stock);
		
		
		printf("Productos del Combo\n");
		for(j=1;j<=tienda.lista_combos.lista[i].cant_elem;j++)
		{
			mostrar_datos(tienda.lista_combos.lista[i].T_combo.lista[j],tienda.lista_combos.lista[i].cant_elem);
			
		}
	}
}
//Modulo actualizar Stock
void actualizar_stock1(T_lista* lis_uni, T_combo* combo_comprado)
{
	int i, j;
	
	for(i=1;i<=combo_comprado->cant_elem;i++)
		for(j=1;j<=lis_uni->can_max;j++)
		if(combo_comprado->T_combo.lista[i].codigo==lis_uni->lista[j].codigo)
			lis_uni->lista[j].stock=lis_uni->lista[j].stock-combo_comprado->T_combo.lista[i].stock;
}
//Modulo buscar_combo
int buscar_combo(T_lista_de_combos lista, T_cadena nom_combo)
{
	int i=1;
	
	while(i<=lista.cant_de_combos && strcmp(lista.lista[i].nombre_combo,nom_combo)!=0)
		i++;
	
	if(i<=lista.cant_de_combos)
		return i;
	else
    return -1;

}
//Modulo Comprar Combo
void Comprar(cliente_carrito* cliente, T_stock* tienda)
{
	int i, j;
	int pos;
  int k;
	T_cadena nom_combo;
	//system("cls");
  system("clear");
  
  mostrar_combos(*tienda);

  //for(i=1;i<=cliente->comb_comprado.cant_de_combos;i++)
  //for(j=1;j<=cliente->comb_comprado.lista[i].cant_elem;j++)
	//mostrar_combos1(&tienda->lista_combos.lista[i].T_combo.lista[j]);
  
	//mostrar_combos(tienda);
	
	__fpurge(stdin);
	printf("\nIngrese la cantidad de combos que desea comprar:");
	scanf("%d",&cliente->comb_comprado.cant_de_combos);
	__fpurge(stdin);
	for(i=1; i<=cliente->comb_comprado.cant_de_combos;i++)
	{
    
		printf("Ingrese el nombre del combo que desea comprar: ");
		leeCad(nom_combo, TMAX);
		//fflush(stdin);
		__fpurge(stdin);
		
		pos=buscar_combo(tienda->lista_combos, nom_combo);
    
   
    
    cliente->comb_comprado.lista[i]=tienda->lista_combos.lista[pos];
    
    
    cliente->importe=cliente->importe+tienda->lista_combos.lista[pos].stock;

  
		
		
    
    
 

   
    //cliente->comb_comprado.cant_de_combos=cliente->comb_comprado.cant_de_combos+1;
		
		actualizar_stock(&tienda->lis_uni, &tienda->lista_combos.lista[pos]);
		
		
		
	}
	
}

void Ordenar_por_codigos(T_stock *tienda){
	int i,j,tam;
  tam=tienda->lis_uni.can_max;
	T_producto aux;
	for (i=1;i<=tam-1;i++)
		for (j=i+1;j<=tam;j++)
			if (tienda->lis_uni.lista[i].codigo>tienda->lis_uni.lista[j].codigo){
				aux=tienda->lis_uni.lista[i];
				tienda->lis_uni.lista[i]=tienda->lis_uni.lista[j];
				tienda->lis_uni.lista[j]=aux; 
			}
}


//FUNCION leecad
void leeCad(char cadena[], int tam){ 
  int j, m; 
  j=0; 
  while(j<tam-1 && (m=getchar())!=EOF && m!='\n'){ 
   cadena[j]=m; 
   j++;} 
   cadena[j]='\0'; 
  if(m != EOF && m != '\n') /*limpia el buffer*/ 
    while((m=getchar())!=EOF && m!='\n'); 
  }

// METODO DE BUSQUEDA BINARIA APLICADA
int busqueda_por_cod(T_stock tienda, int Codigo){
		int I=1,N, MED=0 ,Band=1 ;
		N=tienda.lis_uni.can_max;
		while(I<=N && tienda.lis_uni.lista[MED].codigo!=Codigo && Band==1){
			if(Codigo<tienda.lis_uni.lista[MED].codigo){
				N=MED-1;
				MED=(I+N)/2;
			}
			else{ I=MED+1;
				MED=(I+N)/2;
			}
			if(tienda.lis_uni.lista[MED].codigo==Codigo)Band=0;
		}
		if(Band==1) MED=0;
		return MED;
	}
	
//MODULO CARGAR STOCK DE PRODUCTOS
T_producto cargar_producto(int codigo){
	T_producto aux;
  __fpurge(stdin);
  printf("Ingrese el nombre del producto: ");
  leeCad(aux.nombre_producto,TMAX);
  __fpurge(stdin);
	//fflush(stdin);
  aux.codigo=codigo;
//printf("CODIGO DE %s: %d\n",aux.nombre_producto,aux.codigo);
  	
	printf("Ingrese el precio de %s : ",aux.nombre_producto);
  __fpurge(stdin);
	scanf("%f",&aux.precio);
	printf("Ingrese el Rubro/Categoria de %s: ",aux.nombre_producto);
	__fpurge(stdin);
	//fflush(stdin);
	leeCad(aux.rubro,TMAX);
	printf("Ingrese el Stock de %s : ",aux.nombre_producto);
	scanf("%d",&aux.stock);
	return aux;
}
//MENU CARGAR STOCK DE PRODUCTOS
	void repositar_ini(T_stock *tienda){
		
		int  opc=1,codigo,B=0;
		tienda->lis_uni.can_max=0;
	

		while(opc==1){
	//control
  
			
      system("clear");
      //system("cls");
			printf("\n        INGRESAR PRODUCTO UNITARIO\n\n");
      do{
      printf("\nIngrese el codigo del producto: ");
      scanf("%d",&codigo);
      if(tienda->lis_uni.can_max!=0) B=busqueda_por_cod(*tienda,codigo);
      }while(B!=0);
       tienda->lis_uni.can_max++;
			tienda->lis_uni.lista[tienda->lis_uni.can_max]=cargar_producto(codigo);
      Ordenar_por_codigos(tienda);
      printf("\nDesea ingresar un nuevo producto?\n Si= 1 \n No= 0 \nIngreso: ");
		//fflush();//limpieza del buffer
	  __fpurge(stdin);
			scanf("%d",&opc);
    
		//sprintf("si desea seguir" );
	}//ingreso condicionado
		
		
	}
	
		
		
//MODULOS MENU
char menuAd()
{
	char opc;
	
	do
	{
		//	system("CLS");//Borra la pantalla
		system("clear"); //linux, borrar despues de sesion de replit :D
		printf("        MENU ADMINISTRADOR\n\n");
		printf("1)CARGAR PRODUCTOS: S");
		printf("\n2)CARGAR COMBOS: C");
		printf("\n3)CONTINUAR COMO CLIENTE: E");
		printf("\n\nINGRESO: ");
		scanf("%c",&opc);
    	__fpurge(stdin);
	//fflush(stdin);
	}while(opc!='S'&& opc!='C'&& opc!='E');
	return opc;
}
//MODULO MENU
char menuPrn()
{
	char opc;
	//__fpurge(stdin);
	do
	{
		__fpurge(stdin);
		//system ("CLS");
		system("clear"); //Borra la pantalla,  borrar despues de sesion de replit :D
		printf("      MENU PRINCIPAL DE COMPRAS\n\n");
		printf("-Compra individual: I");
		printf("\n-Compra por Combos: C");
		printf("\n-Borrar producto del carrito: D");
		printf("\n-Borrar producto de un combo: L");
		printf("\n\nIngresar como administrador: A");//aqui
		printf("\nSalir: Z");
		printf("\n\nINGRESO: ");
		scanf("%c",&opc);
    	__fpurge(stdin);
	//fflush(stdin);
	}while(opc!='I'&& opc!='C' && opc!='D' && opc!='L' && opc!='A' && opc!='Z');
	return opc;
}

void aumentar_stock(T_stock* tienda){
	int aux_cod,aux_ubi;
  char C;
	system("clear");
	//system("cls");
	do{
		mostrar_productos(*tienda);
		printf("\n Ingrese codigo del producto a aumentar Stock: ");
		scanf("%d",&aux_cod);
		aux_ubi=busqueda_por_cod(*tienda,aux_cod);
		if(aux_ubi!=0){printf("\n Ingrese el nuevo stock del producto: ");
			scanf("%d",&tienda->lis_uni.lista[aux_ubi].stock);
      
			mostrar_productos(*tienda);
			  printf("\n\nIngrese enter para seguir");
      	__fpurge(stdin);
	//fflush(stdin);
    C=getchar();
      
		}
		else printf("\n\n\n\t------------------ERROR codigo erroneo-----------------");
	}while(aux_ubi==0);
	
}


// Descontinuar producto 
void corrimiento(T_stock *tienda,int aux_ubi){
	int I,N;
	T_producto aux;
	N=tienda->lis_uni.can_max;
	for(I=aux_ubi;I<N;I++) tienda->lis_uni.lista[I]=tienda->lis_uni.lista[I+1];
}

void descontinuar_producto(T_stock *tienda){
	int aux_cod=0,aux_ubi;
  char C;
	system("clear");
	//system("cls");
	do{
	mostrar_productos(*tienda);
	printf("\n Ingrese codigo del producto a descintinuar: ");
	scanf("%d",&aux_cod);
	aux_ubi=busqueda_por_cod(*tienda,aux_cod);
	if(aux_ubi!=0){corrimiento(tienda,aux_ubi);
  system("clear");
	//system("cls");
    tienda->lis_uni.can_max=tienda->lis_uni.can_max-1;
    mostrar_productos(*tienda);
    printf("\n\nIngrese enter para seguir");
      	__fpurge(stdin);
	//fflush(stdin);
    C=getchar();
    
  }
	else printf("\n\n\n\t------------------ERROR codigo erroneo-----------------");
	}while(aux_ubi==0);
	
  	system("clear");
	//system("cls");
  
  
}
//MODULO MENU
char menuAdm1()
{
	char opc;
	
	do
	{
		
		//system("CLS"); 
		system("clear"); //Borra la pantalla,  borrar despues de sesion de replit :D
		__fpurge(stdin);
		printf("      MENU ADMINISTRADOR\n\n");
		printf("1)Descontinuar producto: Q");
		printf("\n2)Descontinuar Combo: W");
		printf("\n3)Aumentar Stock: G");
		printf("\n4)Volver al menu de compras: M");
		printf("\n\nIngreso: ");
		scanf("%c",&opc);
    	__fpurge(stdin);
	//fflush(stdin);
	}while(opc!='Q'&& opc!='W'&& opc!='G'&& opc!='M');
	return opc;
}





//MODULO MENU
void menuadmn3(T_stock *tienda, cliente_carrito* cliente){
	
	char opc1;
	do{
		system("clear"); //Borra la pantalla,  borrar despues de sesion de replit :D
		opc1=menuAdm1();
		switch (opc1){
		case 'Q':	descontinuar_producto(tienda);
			break;
		case 'W': eliminar_pcombo(cliente, tienda);
			break;
		case 'G':aumentar_stock(tienda); 
			break;
		}
	}while (opc1!='M');
}
//MODULO DE BUSCAR CODIGO
	int bus_cod(T_stock tienda, int bus)
	{
		int i=1;
		
		while(i<=tienda.lis_uni.can_max && tienda.lis_uni.lista[i].codigo!=bus)
			i++;
		
		if(i<=tienda.lis_uni.can_max)
			return i;
		else
			return -1;
		
	}
//MODULO MOSTRAR TODOS LOS PRODUCTOS DEL STOCK
	void mostrar_productos(T_stock tienda)
	{
		system("clear");
		//system("cls");
		int i;
		printf("            LISTA DE PRODUCTOS DEL STOCK\n\n");
		printf("Codigo    Nombre    Precio    Rubro   Stock\n");
		for(i=1;i<=tienda.lis_uni.can_max;i++)
    printf("%d    %s    $%2.2f    %s    %d\n",tienda.lis_uni.lista[i].codigo, tienda.lis_uni.lista[i].nombre_producto, tienda.lis_uni.lista[i].precio,tienda.lis_uni.lista[i].rubro, tienda.lis_uni.lista[i].stock);
		printf("\n	--------------------------------------\n\n");
	}




//MODULO CREAR COMBOS
	void crear_combos(T_stock* tienda)
	{ 
		int can_c;
		int i, j;
		int codigo;
		int pos;
    int stock;
		//Precio inicial del combo
    
		//1) Se muestra todos los productos del stock
		mostrar_productos(*tienda);
		
		//2) Se pide la cantidad de combos N
		printf("Cuantos Combos de productos desea Crear?: ");
		scanf("%d",&tienda->lista_combos.cant_de_combos);
  
		
    

		//3) Se repite N veces, indica carga combos
		for(i=1;i<=tienda->lista_combos.cant_de_combos;i++){
      

       //system("cls");
       system("clear");

         __fpurge(stdin);
        //fflush(stdin);

       mostrar_productos(*tienda);
       printf("Ingrese el Nombre/Rubro del combo %d : ",i);
       leeCad(tienda->lista_combos.lista[i].nombre_combo,TMAX);
       //fflush(stdin);
      __fpurge(stdin);
        //system("cls");
       system("clear");
       mostrar_productos(*tienda);

			printf("La Cantidad de productos del Combo %s es : ",tienda->lista_combos.lista[i].nombre_combo);//3)a)
			scanf("%d",&tienda->lista_combos.lista[i].cant_elem);
      //__fpurge(stdin);
      //fflush(stdin);

      //system("cls");
      system("clear");
      mostrar_productos(*tienda);
			
			//printf("\nCODIGO DEL PRODUCTO A AGREGAR AL COMBO: ");
			
			for(j=1; j<=tienda->lista_combos.lista[i].cant_elem;j++)//3)a)a
      {
      //system("cls");
      system("clear");
      mostrar_productos(*tienda);
			
			printf("\nCODIGO DEL PRODUCTO A AGREGAR AL COMBO: ");
				scanf("%d",&codigo);
				
				pos=bus_cod(*tienda, codigo);//3)a)b)

       
				
				tienda->lista_combos.lista[i].T_combo.lista[j]=tienda->lis_uni.lista[pos];

        printf("\nCantidad de %s a agregar al combo %d: ",tienda->lista_combos.lista[i].T_combo.lista[j].nombre_producto, i);
        scanf("%d",&tienda->lista_combos.lista[i].T_combo.lista[j].stock);

        //Stock de la tienda se actualiza (productos de tienda pasan al combo)
        //stock=tienda->lista_combos.lista[i].T_combo.lista[j].stock;//"stock" es la variable cantidad de productos

        tienda->lis_uni.lista[pos].stock=tienda->lis_uni.lista[pos].stock-tienda->lista_combos.lista[i].T_combo.lista[j].stock;//stock tienda menos "stock"

        //Precio del combo (acumulador de precios seleccionados por codigo)
        tienda->lista_combos.lista[i].stock=tienda->lista_combos.lista[i].stock+tienda->lista_combos.lista[i].T_combo.lista[j].stock*tienda->lis_uni.lista[pos].precio;
      }




				
			}
			
		}
    //MUESTRA DE COMPRA INDIVIDUAL/COMBO
     void Mostrar_comp( T_producto lista, int B)
      {
        //system("clear");
        int A=lista.precio*lista.stock;
        
        
        

        printf("Nombre: %s    Precio: %2.2f  c/u: %d, Total $%d\n ",lista.nombre_producto, lista.precio,lista.stock,A);


        //printf("Cantidad de combos Comprados: %d",B);

				
      }
      //MODULO MOSTRAR COMBOS COMPRADOS
      void Mostrar_combos_comprados(T_producto producto, T_cadena nombre, int precio)
      {
        printf("\nNombre: %s    Precio: %f",nombre, producto.precio);
        printf("\nRubro: %s   Stock: %d",producto.rubro, precio);


      }
				// Mostrar compra por unidad y combo
					void mostrar_compra(cliente_carrito cliente){
						int i, N, M;
            int j, k;
            
            
						N=cliente.lista_comprado_uni.can_max;//Cantidad de productos N
            
            //PRODUCTOS INDIVIDUALES
            printf("          Productos comprados Individualmente\n\n");
						for(i=1;i<=N;i++)//RECORRE PRODUCTOS COMPRADOS

          //MUESTRA DATOS PRODUCTOS INDIVIDUALES
					Mostrar_comp(cliente.lista_comprado_uni.lista[i],cliente.comb_comprado.cant_de_combos);
          
          //PRODUCTOS POR COMBO
          M=cliente.comb_comprado.cant_de_combos;
          printf("              Lista de Combos Comprados\n\n");
						for(j=1;j<=M;j++){// Recorrido de combos comprados
            printf("  \nCombo N #%d, Nombre del combo %s\nPrecio Del Combo: %d\n",i,cliente.comb_comprado.lista[i].nombre_combo,cliente.comb_comprado.lista[i].stock);
            
              for(k=1;k<=cliente.comb_comprado.lista[j].cant_elem;k++)
                 //Muestra datos de los productos combo
                 
                  Mostrar_combos_comprados(cliente.comb_comprado.lista[j].T_combo.lista[k], cliente.comb_comprado.lista[j].nombre_combo, cliente.comb_comprado.lista[j].stock);
          }
        
          }

	// MUESTRA PRODUCTO
	
	void	mostrar_producto_comprado(T_producto producto){
			printf("\nNombre de producto: %s \tRubro: %s \tPresio: $%2.2f \tCodigo: %d\n",producto.nombre_producto,producto.rubro,producto.precio,producto.codigo);
			
			
		}
	//COMPRA DE PRODUCTOS
	void comprar_productos_unitario(T_stock *tienda, cliente_carrito *cliente){
		char opc='S';
		int aux_cod,aux_ubi,can_produc;
		float precio=0;
		cliente->lista_comprado_uni.can_max=0;
		
	
		while(opc=='S'){
			system("clear");
			//system("cls");
			mostrar_productos(*tienda);
			printf("\n Ingrese codigo del producto: ");
			scanf("%d",&aux_cod);
			aux_ubi=busqueda_por_cod(*tienda,aux_cod);
			if(aux_ubi!=0){
				system("clear");
				//system("cls");
				cliente->lista_comprado_uni.can_max++;
				mostrar_producto_comprado(tienda->lis_uni.lista[aux_ubi]);
				cliente->lista_comprado_uni.lista[cliente->lista_comprado_uni.can_max]=tienda->lis_uni.lista[aux_ubi];
				printf("\n Cuanto desea comprar de este producto? ");
				scanf("%d",&can_produc);
				tienda->lis_uni.lista[aux_ubi].stock=tienda->lis_uni.lista[aux_ubi].stock-can_produc;
				cliente->lista_comprado_uni.lista[cliente->lista_comprado_uni.can_max].stock=can_produc;
				precio=precio+(tienda->lis_uni.lista[aux_ubi].precio)*can_produc;
				
			}
			else printf("\n codigo ingresado es erroneo ");
			
			printf("\n\n Ingrese S si desea ingresar otro producto a su carrito sino N \nIngreso: ");
     __fpurge(stdin);
      //fflush(stdin);
			scanf("%c",&opc);
     
			cliente->importe=precio;
			
		}
		
		
	}

  


		


	
	void mostrar_productos_comprados(cliente_carrito cliente)
	{
		system("clear");
		//system("cls");
		int i;
		printf("            LISTA DE PRODUCTOS DEL STOCK\n\n");
		printf("Codigo    Nombre    Precio    Rubro   Cant\n");
		for(i=1;i<=cliente.lista_comprado_uni.can_max;i++)
			printf("%d    %s    $%2.2f    %s    %d\n",cliente.lista_comprado_uni.lista[i].codigo, cliente.lista_comprado_uni.lista[i].nombre_producto, cliente.lista_comprado_uni.lista[i].precio, cliente.lista_comprado_uni.lista[i].rubro, cliente.lista_comprado_uni.lista[i].stock);
		printf("\n	--------------------------------------\n\n");
	}
	
	void corrimiento_cliente(cliente_carrito* cliente,int aux_ubi){
		int I,N;
		N=cliente->lista_comprado_uni.can_max;
		for(I=aux_ubi;I<N;I++)cliente->lista_comprado_uni.lista[I]=cliente->lista_comprado_uni.lista[I+1];
	}
	int busqueda_secuencial(cliente_carrito cliente,int codigo){
		int I=1,N=cliente.lista_comprado_uni.can_max,aux=0;
		while(I<=N && codigo!=cliente.lista_comprado_uni.lista[I].codigo){
			I++;
		}
		if(codigo!=cliente.lista_comprado_uni.lista[I].codigo)aux=I;
		return aux;
	}
	void borrar_productto_carrito(cliente_carrito *cliente){
		int aux_cod,aux_ubi;
    char C;
		do{
		mostrar_productos_comprados(*cliente);
		printf("\n Ingrese codigo del producto a eliminar del carrito unitaria: ");
		scanf("%d",&aux_cod);
		aux_ubi=busqueda_secuencial(*cliente,aux_cod);
		if(aux_cod!=cliente->lista_comprado_uni.lista[aux_ubi].codigo){corrimiento_cliente(cliente,aux_ubi);
    cliente->lista_comprado_uni.can_max=cliente->lista_comprado_uni.can_max-1;
    mostrar_productos_comprados(*cliente);
      printf("\n\nIngrese enter para seguir");
      	__fpurge(stdin);
	//fflush(stdin);
    C=getchar();
    }
		else printf("\n\n\n\t------------------ERROR codigo erroneo-----------------");
		}while(aux_ubi==0);
		
	}
	
