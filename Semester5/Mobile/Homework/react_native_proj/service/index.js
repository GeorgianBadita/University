import React from 'react';
import { createStackNavigator } from 'react-navigation-stack';
import { IssueMap } from "./IssueMap";
import { CityIssueEdit } from './CityIssueEdit';
import { CityIssueList } from './CityIssueList';
import { Statistics } from "./Statistics";
import { flipX } from 'react-navigation-transitions';

export const Todo = createStackNavigator({
  ItemList: { screen: CityIssueList },
  ItemEdit: { screen: CityIssueEdit },
  Statistics: {screen: Statistics},
  IssueMap: {screen: IssueMap}
},
{
      transitionConfig: () => flipX(1000)
});

export * from './CityIssueStore';
