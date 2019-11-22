import React from 'react';
import { createAppContainer, createSwitchNavigator } from 'react-navigation';
import { getLogger, navService } from './core';
import { Todo, ItemStore } from './todo';
import { AuthLoading, Auth, AuthStore } from './auth';

const log = getLogger('App');

const AppContainer = createAppContainer(
  createSwitchNavigator(
    { AuthLoading, Todo, Auth },
    { initialRouteName: 'AuthLoading' },
  )
);

const App = () => {
  log('render');
  return (
    <AuthStore>
      <ItemStore>
        <AppContainer ref={navigatorRef => {
          navService.setTopLevelNavigator(navigatorRef);
        }} />
      </ItemStore>
    </AuthStore>
  );
};

export default App;
