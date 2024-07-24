#ifndef LDH_KVMAP_H
#define LDH_KVMAP_H

/**
 * A hashing function - all credit goes to: http://www.cse.yorku.ca/~oz/hash.html
 *
 * @param unsigned char* str    The string to be hash.
 *
 * @return unsigned long        The hashed value.
 */
unsigned long
ldh_Hash(unsigned char *str);

#endif // !LDH_KVMAP_H
