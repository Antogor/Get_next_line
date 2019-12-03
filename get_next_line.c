/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarzon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 14:16:05 by agarzon-          #+#    #+#             */
/*   Updated: 2019/12/03 14:47:31 by agarzon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	/*
	**creamos una cadena que almacene los bytes leidos.
	**Al sumarle + 1 aseguramos que siempre va a ver un byte mas
	**para meter el nulo.
	*/
	char buff[BUFF_SIZE + 1];
	/*
	**creamos una nueva cadena puntero para copiar las lineas leidas
	**ya que las que se van a guaradar en nuestra cadena buff se van a ir sobreescribiendo.
	**Al crearla static hacemos que cada vez que llamemos a esta variable va a guardar el 
	**valor actual. Al ser una cadena estatica la primera vez que la llamemos tendrá su
	**valor inicial, le hacemos los cambios pertinentes y a la siguiente vez que la llamemos
	**tendrá el valor nuevo.
	**Esta cadena es una array que va almacenar en cada posicion un file descriptor
	**eso quiere decir que si tenemos s[1] va a hacer referencia al primer archivo leido.
	**el 4096 es el limite de archivos que se pueden abrir. En realidad es una
	**ARRAY BIDIMENSIONAL
	*/
	static char *s[4096];
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
	while ((bwr = read(fd, buff, BUFF_SIZE))) 
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
		**despues almacenamos los bytes leidos en el file descriptor correspondiente
		*/
		s[fd] = ft_strdup(buff);
	}
	printf("%s\n", s[fd]);
	return (0);
}
