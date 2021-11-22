#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->size=0;
    	this->pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    returnAux=this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	//ll- 4
	//AA20 0
	//AA30 1
	//BB22 2
	//NULL 3
	//Nodeindex = 1
	int index;
	Node* nodoAux=NULL;
	if(this!=NULL && nodeIndex >=0 && ll_len(this)>nodeIndex)
	{
		//AA20
		nodoAux=this->pFirstNode;
				//    0  <  1
		for(index=0;index<nodeIndex;index++)
		{
			//AA30   AA20->AA30
			nodoAux=nodoAux->pNextNode;
		}
	}
    return nodoAux;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
		    Node* pNodo;
		    Node* pNodoAnterior;

		    //printf("Hola, entre al addNode this:%x index:%d pEl%x\n",this,nodeIndex,pElement);

		    if(this!=NULL && nodeIndex>=0 && nodeIndex <= this->size)
		    {
				// construyo un nuevo nodo
				pNodo = (Node*)malloc(sizeof(Node));
				if(pNodo!=NULL)
				{
					pNodo->pElement = pElement; // me guardo

					// diferenciar los 3 casos
					if(nodeIndex==0)
					{
				  		// me quieren agregar el nodo en la primer posicion
						// 1) leer el primer nodo de this y guardarlo en pNodo->next
						pNodo->pNextNode = this->pFirstNode;
						// 2) escribir la dire del nuevo nodo dentro del firstNode de this
						this->pFirstNode = pNodo;
						//3) aumento el size
						this->size++;
					}
					/*
					else if (nodeIndex == this->size)
					{
						// lo agrego al final
						// 1) escribo un NULL en el next del nodo nuevo poque es el ultimo
						pNodo->pNextNode = NULL;
						// 2) Escribir la dire del nodo nuevo en el pNext del Ultimo actual en la lista
						pNodoAnterior = getNode(this,nodeIndex-1);
						pNodoAnterior->pNextNode = pNodo;
						//3) aumento el size
						this->size++;
					}*/
					else
					{
						// son lo' del medio
						//1) Obtengo nodo anterior
						pNodoAnterior = getNode(this,nodeIndex-1);
						//2) le leo la dire del siguiente y la escribo en pNext del nodo nuevo
						pNodo->pNextNode = pNodoAnterior->pNextNode;
						//3) Escribo en el Pnext del anterior, la dire del nuevo
						pNodoAnterior->pNextNode = pNodo;
						//4) aumento el size
						this->size++;
					}

					returnAux=0;
				}

		    }

		    return returnAux;
	/*
	//ll->4
	//AA20 0
	//AA30 1
	//BB22 2
	//NULL 3
	//nodeindex = 0
    int returnAux = -1;
    if(this != NULL && nodeIndex >=0 && ll_len(this)>=nodeIndex)
    {
    	Node* nodoAux;
    	Node* nuevoNodo=(Node*)malloc(sizeof(Node));
    	if(nuevoNodo!=NULL)
    	{
			if(nodeIndex==0) // primer situacion
			{
				//AA20    AA20
				nodoAux = this->pFirstNode;
				//CD20 NUEVO NODO
				this->pFirstNode = nuevoNodo;
				//CD20->AA20
				nuevoNodo->pNextNode = nodoAux;

			}else//ultimo caso
			{
				nodoAux=getNode(this, nodeIndex-1);
				nuevoNodo->pNextNode = nodoAux->pNextNode;
				nodoAux->pNextNode=nuevoNodo;
			}
			this->size++;
			nuevoNodo->pElement = pElement;
			returnAux =0 ;
    	}

    }

    return returnAux;
    */
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
       if(this!=NULL)
       {
           addNode(this, ll_len(this), pElement);
           returnAux = 0;
       }

    return returnAux;
}

/** \brief Trae un elemento de la lista ubicado en el indice indicado(entidad)
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodeAux;
    if(this!=NULL && index>-1 && index<ll_len(this))
    {
    	nodeAux= getNode(this,index);
    	returnAux=nodeAux->pElement;
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pAux;
    if(this != NULL && index >=0 && index<ll_len(this) )
    {
    	pAux=getNode(this, index);
    	pAux->pElement=pElement;
    	returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	 int returnAux = -1;
	    Node *pNode;
	    Node *pNodeAnterior=NULL;

	    if(this != NULL && index >= 0 && index < ll_len(this))
	    {
	    	if(index==0)
	    	{
	    		pNode=this->pFirstNode;
	    		this->pFirstNode=pNode->pNextNode;
	    		free(pNode);
	    	}
	    	else
	    	{
	    		pNode=getNode(this, index);
	    		pNodeAnterior=getNode(this, (index-1));
	    		pNodeAnterior->pNextNode=pNode->pNextNode;
	    		free(pNode);
	    	}
	    	this->size--;
	    	returnAux=0;
	    }


	    return returnAux;
	}

/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
        if(this!=NULL)
        {
        	for(int i=0;i<ll_len(this);i++)
        	{
        		ll_remove(this, i);
        	}
        	this->pFirstNode = NULL;
        	this->size = 0;
        	returnAux=0;
        }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
        {
            ll_clear(this);
            free(this);
            returnAux = 0;
        }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
       Node* nodo;

       if(this!=NULL)
       {
           for(i=0; i<ll_len(this); i++)
           {
               nodo = getNode(this, i);
               if(pElement==nodo->pElement)
               {
                   returnAux = i;
                   break;
               }
           }
       }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
        {
            if(ll_len(this)!=0)
            {
                returnAux = 0;
            }
            else
            {
                returnAux = 1;
            }
        }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && index>=0 && index<=ll_len(this))
        {
            addNode(this, index, pElement);
            returnAux = 0;
        }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
       Node* nodo;
       if(this!=NULL && index>-1 && index<ll_len(this))
       {
           nodo = getNode(this, index);
           returnAux = nodo->pElement;
           ll_remove(this, index);
       }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode;
        if(this!=NULL)
        {
        	returnAux=0;
        	for(int i=0;i<ll_len(this);i++)
        	{
        		pNode=getNode(this, i);
        		if(pNode->pElement==pElement)
        		{
        			returnAux=1;
        			break;
        		}
        	}
        }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
        Node* nodo;
        int auxElement;
        int contador = 0;

        if(this!=NULL && this2!=NULL)
        {
            for(i=0; i<ll_len(this2); i++)
            {
                nodo = getNode(this2, i);
                auxElement = ll_contains(this, nodo->pElement);

                if(auxElement==1)
                {
                    contador++;
                }

            }

            if(contador==ll_len(this2))
            {
                returnAux = 1;

            } else {

                returnAux = 0;
            }
        }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
       void* pElement;

       if(this!=NULL && from>-1 && from<=ll_len(this) && to>=from && to<=ll_len(this))
       {
           cloneArray = ll_newLinkedList();

           if(cloneArray!=NULL)
           {
               for(i=from; i<to; i++)
               {
                   pElement = ll_get(this, i);
                   ll_add(cloneArray, pElement);
               }
           }
       }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    void* pElement;
    int i;
        if(this!=NULL)
        {
            cloneArray = ll_newLinkedList();

            if(cloneArray!=NULL)
            {
                for(i=0; i<ll_len(this); i++)
                {
                    pElement = ll_get(this, i);
                    ll_add(cloneArray, pElement);
                }
            }
        }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
       void* thisA;
       void* thisB;
       int flagSwap;
       int returnOrderValue;
       if(this!=NULL && ll_len(this)>0 && pFunc!=NULL && (order==0 || order==1))
       {
           do
           {
               flagSwap=0;
               for(i=0;i<ll_len(this)-1;i++)
               {
                   thisA=ll_get(this,i);
                   thisB=ll_get(this,i+1);
                   if(thisA!=NULL && thisB!=NULL)
                   {
                       returnOrderValue=pFunc(thisA,thisB);
                       if((returnOrderValue==-1 && order==0) || (returnOrderValue==1 && order==1))
                       {
                           flagSwap=1;
                           ll_set(this,i,thisB);
                           ll_set(this,i+1,thisA);
                       }
                   }
               }
           }while(flagSwap==1);
           returnAux=0;
       }
    return returnAux;

}
int ll_map(LinkedList* this,int (*pFunc)(void*))
{
	int retorno=-1;
	int i;
	void* pAux;
	//verificar nulidad
	//recorrer lista
	//tomar el elemento
	//tomo el elemento lo mapeo
	if(this!=NULL && pFunc!=NULL)
	{
		//RECORRO LA LISTA
		for(i=0;i<ll_len(this);i++)
			//tomo el elemento
		{
			pAux=ll_get(this, i);
			if(pAux!=NULL)
			{
				//MAPEO
				pFunc(pAux);
			}
		}
		retorno=0;
	}
	return retorno;

}
int ll_filter (LinkedList* this , int (pFunc)(void*))
{
	int returnAux = -1;
		int criterio;
		void* pAuxiliar;

		if(this != NULL && pFunc != NULL){
			//RECORRER MI LISTA
			for(int i=ll_len(this)-1; i >= 0; i--){
				//TOMO EL ELEMENTO
				pAuxiliar = ll_get(this, i);

				if(pAuxiliar != NULL){
					//FILTRO
					criterio = pFunc(pAuxiliar);
					//Si criterio == 0, entonces lo elimino.
					if(criterio == 0){
						returnAux = ll_remove(this, i);
					}
				}
			}

		}

		return returnAux;
}
