Dans ce Readme je vais répondre au question du TP et pottentiellement expliqué si je fait des choses hors du commun.

# TP1 : 
## Comment appelle-t-on ce type de méthode et comment faut-il les déclarer ?

il s’agit de méthodes virtuelles pures.
Lorsqu'on les déclare dans la classe de base on écrit virtual sans la définir et on la définit dans les sous-classes.

## Pourquoi ne sera-t-il plus possible d’instancier des objets de la classe de base après cela ?

Une classe contenant au moins une méthode virtuelle pure est considérée comme une classe abstraite. Les classes abstraites ne peuvent pas être instanciées directement parce qu’elles ne définissent pas totalement leur comportement



## Quelle est la propriété caractéristique de l’orienté objet qui permet de faire cela ?
La propriété clé est le polymorphisme. Cela permet de manipuler des objets de classes dérivées via un pointeur ou une référence vers leur classe de base, et ainsi d’appeler les méthodes appropriées (celles des classes dérivées réelles) sans connaître le type concret de l’objet au moment de la compilation.

## Qu’est-il spécifiquement nécessaire de faire dans le cas du C++ ?
En C++, pour bénéficier du polymorphisme dynamique, il est nécessaire de déclarer les méthodes que l’on souhaite appeler de manière polymorphe comme étant virtuelles dans la classe de base. Autrement dit, il faut utiliser le mot-clé virtual devant la méthode dans la classe de base. Cela permet, lorsque l'on appele une méthode via un pointeur (ou une référence) de type classe de base, d’exécuter la version de la méthode définie dans la classe dérivée réelle de l’objet pointé.

## Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java.
Le tableau doit contenir des pointeurs vers la classe de base et non directement des objets de la classe de base. En effet, en C++, stocker un objet dérivé dans un tableau d’objets de la classe de base est problématique : en effet, seule la partie « base » de l’objet dérivé serait conservée, perdant ainsi les informations spécifiques à la classe dérivée. En utilisant des pointeurs (ou des références), on conserve l’identité dynamique de l’objet, et le mécanisme de liaison tardive fonctionne correctement.


## Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit les objets ? Modifiez le code de manière à l'éviter.

La classe film correspond car c'est la seul où l'on utilise "new[]" et que c'est la seule classe qui utilise des pointeurs. elle a été modifié en conséquence.

lorsque l'on veut copier un élément il faut faire attention à ne pas copier l'adresse car sinon on risque de modifier l'élément original. Il faut avoir une nouvelle adresse où l'on libère de l'espace pour mettre la copie

## 10e étape

Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ? 

il faudrait alors mettre la création de classe dans un protected et après rajouter des friend *nomdelaclasse*

