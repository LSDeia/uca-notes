import java.util.ArrayList;
import java.util.List;

public class Farm {
    List<Animal> farmList;

    Farm(){
        this.farmList = new ArrayList<Animal>();
    }

    public void switchAllToWinter(){
        for(Animal animal: this.farmList){
            animal.switchToWinter();
            checkForDeath();
        }
    }

    public void checkForDeath(){
        for(Animal animal: this.farmList){
            if (animal.health <= 0)
            {
                this.farmList.remove(animal);
                Display.death(animal);
            }
        }
    }

    public void add(Animal a){
        this.farmList.add(a);
    }
}
