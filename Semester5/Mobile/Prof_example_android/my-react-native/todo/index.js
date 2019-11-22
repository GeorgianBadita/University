import React from 'react';
import { createStackNavigator } from 'react-navigation-stack';

import { ItemEdit } from './ItemEdit';
import { ItemList } from './ItemList';

export const Todo = createStackNavigator({
  ItemList: { screen: ItemList },
  ItemEdit: { screen: ItemEdit },
});

export * from './ItemStore';
