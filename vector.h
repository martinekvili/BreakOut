#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <cmath>

/**
 * Vektor oszt�ly.
 *
 * A vil�g koordin�t�kat t�roljuk ebben.
 */
struct Vector {
    /**
     * Az x koordin�ta.
     */
    float x;

    /**
     * Az y koordin�ta.
     */
    float y;

    /**
     * Konstruktor.
     * @param x Az x koordin�ta.
     * @param y Az y koordin�ta.
     */
    Vector(float x, float y) : x{x}, y{y} {}

    /**
     * Skal�rral val� szorz�s.
     * @param n A skal�r amivel szorzunk.
     * @return A szorzat.
     */
    Vector operator* (float n);

    /**
     * K�t vektor �sszege.
     * @param other A m�sik tag.
     * @return Az �sszeg.
     */
    Vector operator+ (const Vector& other);

    /**
     * Skal�rral val� szorz�s.
     * @param n A skal�r amivel szorzunk.
     * @return A szorzat.
     */
    Vector& operator*= (float n);

    /**
     * K�t vektor �sszege.
     * @param other A m�sik tag.
     * @return Az �sszeg.
     */
    Vector& operator+= (const Vector& other);
};

#endif // VECTOR_H_INCLUDED
