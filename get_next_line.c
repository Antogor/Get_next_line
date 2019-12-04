/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:16:05 by agarzon-          #+#    #+#             */
/*   Updated: 2019/12/03 17:54:39 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
**Con esta función comprobamos si se ha leido solo una linea y la limpiamos de
**caracteres sobrantes para que solo salga la linea.
*/
static int	ft_comp_new_line(char **s, char **line)
{
	/*
	**Necesitaremos un contandor para recorrer las cadenas. Y una cadena temporal
	**para que se pueda avanzar por cada salto de linea leido.
	*/
	int		l;
	char	*tmp;
	/*
	**Comprobamos el contenido de s, para hacerlo tenemos que utilizar la
	**sintaxis de los punteros, con (*s) veriamos el contenido de lo que apunta ese puntero.
	**Debemos avanzar el contador hasta que encontremos el salto de linea o un nulo.
	*/
	l = 0;
	while ((*s)[l] != '\n' && (*s)[l] != '\0')
		l++;
	/*
	**Una vez llegado a uno de esos dos caracteres comprobamos si es el '\n', si es así
	**nos disponimos a limpiar la linea de los caracteres sobrantes trans el '\n'.
	*/
	if ((*s)[l] == '\n')
	{
		/*
		**Guardamos en la cadena que mandamos en el main la linea limpia.
		**Para eso utilizamos la funcion substr. Mandamos el contenido de s, la posición 0
		**de esa cadena, y tantos bytes para copiar como el tamaño de l, que es el anterior
		**a nuestro '\n'
		*/
		*line = ft_substr(*s, 0, l);
		/*
		**Con la cadena temporal hacemos un duplicado de los bytes restantes mandados,
		**saltandonos el '\n' de la linea anterior.
		**Liberamos los residuos de s, y la dejamos solo con lo que queda.
		*/
		tmp = ft_strdup(&(*s)[l + 1]);
		free(*s);
		*s = tmp;
	}
	else if ((*s)[l] == '\0')
	{
		/*
		**Si en vez de '\n' encontramos el '\0', solo duplicamos la s actual en la cadena
		**que tenemos en el main.
		*/
		*line = ft_strdup(*s);
		return (0);
	}
	return (1);
}


/*
**Funcion para comprobar que los x bytes leidos.
**Es estatica para que mantenga los valores anteriores.
*/
static int	ft_comp(int bwr, int fd, char **s, char **line)
{
	if (bwr < 0)
		return (-1);
	/*
	**En el else if comprobamos que si los bytes leidos son 0 y que la posición acutal de s
	**es nula, quiere decir que hemos encontrado el nulo del texto y lo hemos leido todo.
	*/
	else if (bwr == 0 && s[fd] == NULL)
		return (0);
	/*
	**Para lo demás el resultado a devolver será 1. El problema es que hay que devolver 1
	**y la linea leida, por lo que todo caracter que vaya despues del '\n' encontrado,
	**si lo hubiera, tiene que borrarse.
	**Como para eso va a necesitarse mas espacio, se crea una nueva funcion. 
	*/
	else
		/*
		**Le mandamos a la funcion la posicion actual de s (como es una array bi le estamos
		**mandado la fila correspondiente), que son los bytes leidos hasta ahora.
		*/
		return (ft_comp_new_line(&s[fd], line));
}


int			get_next_line(int fd, char **line)
{
	/*
	**creamos una cadena que almacene los bytes leidos.
	**Al sumarle + 1 aseguramos que siempre va a ver un byte mas
	**para meter el nulo. 
	**BUFF_SIZE es una macro que determina cuantos bytes se van a leer, en este caso
	**esos bytes nos son dados a la hora de compilar con la bandera:
	**gcc -D <nombre de la macro>=<valor que queremos darle>.
	*/
	char buff[BUFFER_SIZE + 1];
	/*
	**creamos una nueva cadena puntero para copiar las lineas leidas
	**ya que las que se van a guaradar en nuestra cadena buff se van a ir sobreescribiendo.
	**Al crearla static hacemos que cada vez que llamemos a esta variable va a guardar el 
	**valor actual. Al ser una cadena estatica la primera vez que la llamemos tendrá su
	**valor inicial, le hacemos los cambios pertinentes y a la siguiente vez que la llamemos
	**tendrá el valor nuevo.
	**Esta cadena es una array que va almacenar en cada posicion un file descriptor
	**eso quiere decir que si tenemos s[3] va a hacer referencia al primer archivo leido.
	**el 4096 es el limite de archivos que se pueden abrir. Y el primer archivo
	**siempre va a ser 3 porque el 0, 1, y 2 estan reservados para la entrada, salida, 
	**y errores respectivamente.
	**Esta cadena en realidad es una
	**ARRAY BIDIMENSIONAL
	*/
	static char *s[4096];
	char *tmp;
	/*
	**en este entero se almecenan el numero de bytes leidos
	**bwr = bytes was read
	*/
	int bwr;
	/*
	**comprobamos que lo que nos mandan no esta vacio
	*/
	if (fd < 0 || line == 0)
		return (-1);
	/*
	**creamos un bucle que indique que mientras el archivo exista 
	**vaya leyendo tantos bytes mandados hasta que acabe
	**el archivo y vaya metiendo esos bytes leidos 
	**en la cadena buff, el ultimo numero variara 
	**dependiendo de los bytes que queden.
	**Cada vuelta del bucle depende del numero de bytes que
	**le hayamos dicho que lea, cuando llegue al maximo
	**el bucle volverá a empezar. !la cadena buff debe 
	**tener la misma capacidad que los bytes leidos. 
	*/
	while ((bwr = read(fd, buff, BUFFER_SIZE))) 
	{
		/*
		**al ponerle como posicion a la cadena buff el numero actual de bytes leidos
		**hacemos referencia a la posicion actual de la cadena antes
		**de que de la vuelta al bucle. Y como el tamaño va a ser igual
		**al numero de bytes que queremos leer + 1, siempre habrá hueco
		**para meter el nulo al final de cada vuelta de bytes leidos.
		**Cada vuelta debe acabar en nulo. Por cada vuelta del bucle borra lo que
		**se haya guardado en la anterior. Por lo que siempre tendremos los ultimos
		**bytes mandados a leer del documento.
		*/
		buff[bwr] = '\0';
		/*
		**despues almacenamos los primero bytes leidos en la poscion del file descriptor 
		**correspondiente a nuestra cadena bi. Al iniciar el bucle s[fd] es nulo por lo que
		**entrará aquí y copiará los primeros bytes leidos y almacenados en buff
		*/
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		/*
		**A la segunda vuelta del bucle, utilizamos else para guardar
		**en un puntero nuevo los bytes guardados en s, y le concatenamos los bytes actuales
		**de buff. Al ser s una cadena estatica el valor no se sobreescribe al igual que 
		**hace la cadena buff. Entonces lo que hacemos en el else, es añadir a lo que tenemos
		**acumulado en s, los bytes almacenados en buff.
		*/
		else
		{
			tmp = ft_strjoin(s[fd], buff);
			/*
			**Liberamos s[fd] para borrar de la memoria las versiones incompletas del texto
			**almacenadas en s[fd]. Asi de esta manera nos aseguramos que cuando acabe el bucle
			**s[fd] contiene todo el texto y las versiones anteriores no estan ocupando
			**espacio en la memoria.
			*/
			free(s[fd]);
			s[fd] = tmp;
		}
		/*
		**Con esta prueba vemos si al leer los bytes encuentra un salto de linea.
		**El bucle no parará hasta que no encuentre el salto de linea. Al primer '\n' parará
		**independientemente de los bytes mandados a leer.
		*/
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	/*
	**Ahora es cuando hacemos las comprobaciones que devuelve la funcion.
	**Si de los x bytes mandados, encuentra el salto de linea y no es la última linea,
	**la funcion devuelve un 1 (se ha leido una linea).
	**Si encuentra el salto de linea y es la ultima linea del texto,
	**la funcion devuelve 0 (Se ha leido todo el archivo).
	**Para cualquier otro error, la función devuelve -1.
	**Para esto nos vamos a otra función.
	*/
	return (ft_comp(bwr, fd, s, line));
}
