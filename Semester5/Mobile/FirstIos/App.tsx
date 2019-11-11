import React, { Component } from 'react';
import Main from './app/components/Main';
import AddMeal from './app/components/AddMeal'
import { createAppContainer} from 'react-navigation';
import {createStackNavigator} from 'react-navigation-stack';

const AppStackNavigator = createStackNavigator(
  {
    AddScreen: AddMeal,
    MainScreen: Main,
    
  },{
    initialRouteName: 'AddScreen',
    headerMode: 'none',
  }
);

const App = createAppContainer(AppStackNavigator);
export default App;