/*
** EPITECH PROJECT, 2024
** amazed_mirror
** File description:
** ceil.c
*/

/*!
 * @file ceil.c
*/

/*!
 *
 * @param nb
 * @return
*/
int my_ceil(double nb)
{
    if ((int)nb != nb)
        return (int)nb + 1;
    return (int)nb;
}

/*!
 *
 * @param nb
 * @return
 */
int my_floor(double nb)
{
    return (int)nb;
}
