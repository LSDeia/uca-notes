import java.time.LocalDate;
import java.util.Date;

public abstract class Animal {
    String name;
    String dateOfBirth;
    int health = 90; // Animals have health and dies after reaching 0

    Animal(String name, String dateOfBirth){
        this.name = name;
        this.dateOfBirth = dateOfBirth;
    }

    // Function to simulate winter season
    void switchToWinter(){
        System.out.println("This function needs to be override");
    }

    @Override
    public String toString(){
        return "Name: " + this.name + " Date Of Birth: " + this.dateOfBirth;
    }
}
