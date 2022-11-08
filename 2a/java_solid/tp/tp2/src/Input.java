import java.time.LocalDate;
import java.util.Scanner;

public class Input {
    Input(){};

    public static Chipmunk enterChipmunk(){
        Scanner scA = new Scanner(System.in);
        System.out.println("Name: ");
        String name = scA.nextLine();

        Scanner scB = new Scanner(System.in);
        System.out.println("Date Of Birth: ");
        String date = scB.nextLine();

        Scanner scC = new Scanner(System.in);
        System.out.println("Number Of Seeds: ");
        int seeds = scC.nextInt();
        return new Chipmunk(name, date, seeds);
    }

    public static Kangaroo enterKangaroo(){
        Scanner scA = new Scanner(System.in);
        System.out.println("Name: ");
        String name = scA.nextLine();

        Scanner scB = new Scanner(System.in);
        System.out.println("Date Of Birth: ");
        String date = scB.nextLine();

        Scanner scC = new Scanner(System.in);
        System.out.println("Number Of Uppercut: ");
        int uppercut = scC.nextInt();
        return new Kangaroo(name, date, uppercut);
    }

    public static int enterMenu(){
        Scanner sc = new Scanner(System.in);
        return sc.nextInt();
    }
}
