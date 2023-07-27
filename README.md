# Philosophers
Ce projet est une introduction au threading et aux processus, et sur comment travailler sur le même espace mémoire.

Fonctions autorisées : 

| Nom de la fonction   | Description de la fonction                          | Prototype de la fonction                                      | Bibliothèque           |
|----------------------|----------------------------------------------------|---------------------------------------------------------------|------------------------|
| memset               | Remplit un bloc de mémoire avec une valeur donnée  | `void *memset(void *ptr, int value, size_t num);`             | string.h               |
| printf               | Affiche du texte formaté sur la sortie standard    | `int printf(const char *format, ...);`                       | stdio.h                |
| malloc               | Alloue dynamiquement de la mémoire                 | `void *malloc(size_t size);`                                 | stdlib.h               |
| free                 | Libère la mémoire précédemment allouée            | `void free(void *ptr);`                                      | stdlib.h               |
| write                | Écrit des données dans un descripteur de fichier   | `ssize_t write(int fd, const void *buf, size_t count);`      | unistd.h               |
| usleep               | Suspend l'exécution du programme pendant un temps donné (en microsecondes) | `int usleep(useconds_t microseconds);`               | unistd.h |
| gettimeofday        | Récupère le temps actuel du système                | `int gettimeofday(struct timeval *tv, struct timezone *tz);` | sys/time.h             |
| pthread_create       | Crée un nouveau thread                              | `int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);` | pthread.h  |
| pthread_detach       | Détache le thread, permettant la terminaison asynchrone | `int pthread_detach(pthread_t thread);`                      | pthread.h              |
| pthread_join         | Attend la fin d'un thread donné                    | `int pthread_join(pthread_t thread, void **retval);`         | pthread.h              |
| pthread_mutex_init   | Initialise un objet de verrouillage (mutex)        | `int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);` | pthread.h  |
| pthread_mutex_destroy| Détruit un objet de verrouillage (mutex)           | `int pthread_mutex_destroy(pthread_mutex_t *mutex);`         | pthread.h              |
| pthread_mutex_lock   | Verrouille un mutex                                 | `int pthread_mutex_lock(pthread_mutex_t *mutex);`            | pthread.h              |
| pthread_mutex_unlock | Déverrouille un mutex                               | `int pthread_mutex_unlock(pthread_mutex_t *mutex);`          | pthread.h              |


