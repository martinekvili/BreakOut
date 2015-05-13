#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <cmath>

/**
 * Vektor osztály.
 *
 * A világ koordinátákat tároljuk ebben.
 */
struct Vector {
    /**
     * Az x koordináta.
     */
    float x;

    /**
     * Az y koordináta.
     */
    float y;

    /**
     * Konstruktor.
     * @param x Az x koordináta.
     * @param y Az y koordináta.
     */
    Vector(float x, float y) : x{x}, y{y} {}

    /**
     * Skalárral való szorzás.
     * @param n A skalár amivel szorzunk.
     * @return A szorzat.
     */
    Vector operator* (float n);

    /**
     * Két vektor összege.
     * @param other A másik tag.
     * @return Az összeg.
     */
    Vector operator+ (const Vector& other);

    /**
     * Skalárral való szorzás.
     * @param n A skalár amivel szorzunk.
     * @return A szorzat.
     */
    Vector& operator*= (float n);

    /**
     * Két vektor összege.
     * @param other A másik tag.
     * @return Az összeg.
     */
    Vector& operator+= (const Vector& other);
};

#endif // VECTOR_H_INCLUDED
