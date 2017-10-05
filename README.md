# FdF
Projet 42 - Langage C - FdF
-----------------------------------------------------------------------------------------------------------------------------------------------

Le projet FdF présente les bases de la programmation graphique, et en particulier, le placement de points dans l’espace, comment les relier avec des segments et surtout comment observer la scène depuis un certain point de vue.

Nous découvrons également notre première bibliothèque graphique: La miniLibX.

Cette bibliothèque développée en interne (42) rassemble le minimum nécéssaire pour ouvrir une fenêtre, allumer un pixel et gérer les évènements lié à cette fenêtre : le clavier, la souris et l’“expose”. 

Ce projet est également l’occasion de nous initier à la programmation dite “evenementielle”.

Vous trouverez également dans le repository un dossier "maps" contenant diverses cartes mises à disposition afin de pouvoir exécuter convenablement le programme, cependant rien ne vous empêche d'en créer d'autres !

(INFO: Certaines cartes contiennent volontairement des erreurs de remplissage, afin de pouvoir tester certains cas d'erreurs)

Toutes les fonctions présentes ont été prototypées dans le fichier "fdf.h" situé dans le dossier "includes" et nous utilisons egalement notre Libft mise à jour avec les fonctions précédemment utilisées au cours des derniers projets.

L'ensemble du projet est compilable dans un environnement OSX (Sierra 10.12.6), via le Makefile. Les règles a dispositions sont les suivantes:
- make
  - clean 
  - fclean
  - re
  
-----------------------------------------------------------------------------------------------------------------------------------------------
mtacnet@student.42.fr
