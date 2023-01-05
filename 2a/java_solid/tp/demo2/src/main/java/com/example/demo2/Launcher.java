package com.example.demo2;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class Launcher extends Application
{
    @Override
    public void start(Stage primaryStage) throws IOException
    {
        FXMLLoader fxmlLoader = new FXMLLoader(Launcher.class.getResource("thermometer.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 320, 240);

        primaryStage.setTitle("Hello!");
        primaryStage.setScene(scene);
        primaryStage.show();

        Stage stage1 = new Stage();
        stage1.setTitle("Hello!2");
        stage1.setScene(scene);
        stage1.show();
    }

    public static void main(String[] args)
    {
        launch();
    }
}