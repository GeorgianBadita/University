import { createStackNavigator } from 'react-navigation-stack';

import { SignIn } from './SignIn';

export const Auth = createStackNavigator({
  SignIn: { screen: SignIn },
});

export * from './AuthLoading';
export * from './AuthStore';
