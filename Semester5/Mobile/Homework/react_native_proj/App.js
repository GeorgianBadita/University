import React from 'react';
import { createAppContainer, createSwitchNavigator } from 'react-navigation';
import { getLogger, navService } from './core';
import { Todo, CityIssueStore } from './service';
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
      <CityIssueStore>
        <AppContainer ref={navigatorRef => {
          navService.setTopLevelNavigator(navigatorRef);
        }} />
      </CityIssueStore>
    </AuthStore>
  );
};

export default App;