package com.example.demo;

import javafx.fxml.FXML;
import javafx.scene.control.Label;

public class HelloController {
    @FXML
    private Label welcomeText;

    @FXML
    protected void onHelloButtonClick1() {
        welcomeText.setText("Welcome to JavaFX Application!");
    }
    @FXML
    protected void onHelloButtonClick2() {
        welcomeText.setText("Welcome to JavaFX Application!");
    }
    @FXML
    protected void onHelloButtonClick3() {
        welcomeText.setText("Welcome to JavaFX Application!");
    }
    @FXML
    protected void onHelloButtonClick4() {
        welcomeText.setText("Welcome to JavaFX Application!");
    }
}