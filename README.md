# Philosophers
Ce projet est une introduction au threading et aux processus, et sur comment travailler sur le même espace mémoire.

Fonctions autorisées : 

| Nom de la fonction   | Description de la fonction                          | Bibliothèque           |
|----------------------|----------------------------------------------------|------------------------|
| memset               | Remplit un bloc de mémoire avec une valeur donnée  | string.h               |
| printf               | Affiche du texte formaté sur la sortie standard    | stdio.h                |
| malloc               | Alloue dynamiquement de la mémoire                 | stdlib.h               |
| free                 | Libère la mémoire précédemment allouée            | stdlib.h               |
| write                | Écrit des données dans un descripteur de fichier   | unistd.h               |
| usleep               | Suspend l'exécution du programme pendant un temps donné (en microsecondes) | unistd.h |
| gettimeofday        | Récupère le temps actuel du système                | sys/time.h             |
| pthread_create       | Crée un nouveau thread                              | pthread.h              |
| pthread_detach       | Détache le thread, permettant la terminaison asynchrone | pthread.h          |
| pthread_join         | Attend la fin d'un thread donné                    | pthread.h              |
| pthread_mutex_init   | Initialise un objet de verrouillage (mutex)        | pthread.h              |
| pthread_mutex_destroy| Détruit un objet de verrouillage (mutex)           | pthread.h              |
| pthread_mutex_lock   | Verrouille un mutex                                 | pthread.h              |
| pthread_mutex_unlock | Déverrouille un mutex                               | pthread.h              |
