import java.util.List;

public class Display {

    Display(){}

    static void animal(Animal a){
        System.out.println(a);
    }

    static void death(Animal a){
        System.out.println("[" + a.name + "] I am dead :(");
    }

    static void farm(List<Animal> l){
        for(Animal animal: l){
            animal(animal);
        }
    }

    static void menu(){
        System.out.println("MENU");
        System.out.println("-----------------------");
        System.out.println("1 : Add Chipmunk");
        System.out.println("2 : Add Kangaroo");
        System.out.println("3 : Display all Farm");
        System.out.println("4 : Switch farm to winter mode");
        System.out.println("Anything : Stop Program");
        System.out.println("-----------------------");
        System.out.println("Your Choice: ");
    }
}
