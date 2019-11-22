import React, { useCallback, useContext, useEffect } from 'react';
import { ItemContext } from './ItemContext';
import { getLogger, httpGet, httpPost } from '../core';
import { AuthContext } from '../auth/AuthContext';

const log = getLogger('ItemStore');

const initialState = {
  isLoading: false,
  items: null,
  loadingError: null,
};

export const ItemStore = ({ children }) => {
  const [state, setState] = React.useState(initialState);
  const { isLoading, items, loadingError } = state;
  const { token } = useContext(AuthContext);

  useEffect(() => {
    if (token && !items && !loadingError && !isLoading) {
      log('load items started');
      setState({ isLoading: true, loadingError: null });
      httpGet('api/item')
        .then(json => {
          log('load items succeeded');
          setState({ isLoading: false, items: json });
        })
        .catch(loadingError => {
          log('load items failed');
          setState({ isLoading: false, loadingError })
        });
    }
  }, [token]);

  const onSubmit = useCallback(async (item) => {
    log('post item started');
    log(item);
    return httpPost('api/item', item)
      .then(json => {
        log('post item succeeded');
        setState({ items: items.concat(json) });
        return Promise.resolve(json);
      })
      .catch(error => {
        log('post item failed');
        return Promise.reject(error);
      });
  });

  log('render', isLoading);
  const value = { ...state, onSubmit };
  return (
    <ItemContext.Provider value={value}>
      {children}
    </ItemContext.Provider>
  );
};
