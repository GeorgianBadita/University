import React, { useCallback, useContext, useEffect } from 'react';
import { CityIssueContext } from './CityIssueContext';
import { getLogger, httpGet, httpPost, wsApiUrl } from '../core';
import { AuthContext } from '../auth/AuthContext';
import { AsyncStorage, NetInfo } from 'react-native';

var uuidv1 = require('uuid/v1');

const log = getLogger('CityIssueStore');

export const ONLINE_ITEMS = 'ONLINE_ITEMS';
export const OFFLINE_ITEMS = 'OFFLINE_ITEMS';

/*
AsyncStorage.setItem(ONLINE_ITEMS, JSON.stringify({}));
AsyncStorage.setItem(OFFLINE_ITEMS, JSON.stringify({}));
/*

*/


const initialState = {
  isLoading: false,
  items: null,
  loadingError: null,
};

export const CityIssueStore = ({ children }) => {
    const [state, setState] = React.useState(initialState);
    const [connected, setIsConnected] = React.useState({isConnected: false});
    const {isConnected} = connected;
  const { isLoading, items, loadingError} = state;
  const { token } = useContext(AuthContext);

  const ws = new WebSocket(wsApiUrl);

  useEffect(() => {
      NetInfo.getConnectionInfo().then((connectionInfo) => {
          console.log(
              'Initial, type: ' +
              connectionInfo.type
          );
          if (connectionInfo.type === 'wifi'){
              setState({isConnected:  true});
              connectionIsPresent();
          }
          else {
              setState({isConnected: false})
          }
      });
      function handleConnectivityChange(connectionInfo) {
          console.log(
              'change, type: ' +
              connectionInfo.type
          );

          if (connectionInfo.type === 'wifi'){
              //setState(Object.assign({}, state, {isConnected:  true}));
              setIsConnected({isConnected:  true});
              connectionIsPresent();
          }
          else {
              //setState(Object.assign({}, state, {isConnected:  false}));
              setIsConnected({isConnected: false});
          }
      }
      NetInfo.addEventListener('connectionChange', handleConnectivityChange);

    return () => {
        console.log('CLOSING STORE')
    }
  }, [token]);





  const connectionIsPresent = () => {
      ws.onopen = evt =>{
          console.log('connected')
      };

      ws.onmessage = evt =>{
          console.log('update coming from ws');
          var cityIssue = JSON.parse(evt.data).data;

          AsyncStorage.getItem(ONLINE_ITEMS).then( x=>{
              var online_items_list = JSON.parse(x);
              AsyncStorage.getItem(OFFLINE_ITEMS).then( x=>{
                  var json = cityIssue;
                  var offline_items_list = JSON.parse(x);
                  //console.log(online_items_list);
                  //online_items_list[json._id] = json;
                  AsyncStorage.setItem(ONLINE_ITEMS, JSON.stringify(online_items_list));
                  var all = Object.assign({}, online_items_list, offline_items_list);
                  var arr = [];
                  for (var key in all) {
                      arr.push(all[key]);
                  }
                  //setState(Object.assign({}, state, {items: arr}));

                  setState({ items: arr });
              });
          });
          //console.log(JSON.parse(evt.data));
      };
        console.log('#############################################################################################')
      if (token && !loadingError && !isLoading) {
          log('load items started');
          setState(Object.assign({}, state, { isLoading: true, loadingError: null }));
          //setState();
          console.log("DDDDD");
          httpGet('api/item')
              .then(async json => {
                  log('load items succeededFIRST');
                  log(JSON.stringify(json));

                      var online_items_list = {};

                      for (var idx in json){
                          var el = json[idx]
                          var k =  el._id;
                          log(el)
                          log(k)
                          online_items_list[k]=el;
                      }

                      console.log('REFRESH'+JSON.stringify(online_items_list));
                      await AsyncStorage.getItem(OFFLINE_ITEMS).then(async x=>{
                          var offline_items_list = JSON.parse(x);
                          for (var key in offline_items_list) {
                              var item = offline_items_list[key];
                              online_items_list[key] = item;
                              httpPost('api/item', item)
                                  .then(json => {
                                      log('post item succeeded');
                                      //
                                      // log(JSON.stringify(json));
                                      console.log('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
                                      return Promise.resolve(json);

                                  })
                                  .catch(error => {
                                      log('post item failed');
                                      return Promise.reject(error);
                                  });
                          }
                          await AsyncStorage.setItem(OFFLINE_ITEMS, JSON.stringify({})).then(() => {
                              AsyncStorage.setItem(ONLINE_ITEMS, JSON.stringify(online_items_list)).then(() => {
                                  var all = Object.assign({}, online_items_list);
                                  var arr = [];
                                  for (var key in all) {
                                      arr.push(all[key]);

                                  }
                                  //setState(Object.assign({}, state, {items: arr}));
                                  setState({ items: arr });
                              })
                          })
                  });

                  //setState(Object.assign({}, state, {isLoading: false}));
                  setState({ isLoading: false});

              })
              .catch(loadingError => {
                  log('load items failed');
                  //setState(Object.assign({}, state, {isLoading: false, loadingError}));
                  setState({ isLoading: false, loadingError })
              });
      }


  };

  const onSubmit = useCallback(async (item) => {
    log('post item started');
    // TODO asta ar trb numa cand nu e net, si can e pui in lo de uuidv1() id u returnat de post
      AsyncStorage.getItem(ONLINE_ITEMS).then( x=>{
          log("ONLINE SOURCE"+x);
          var online_items_list = JSON.parse(x);
          AsyncStorage.getItem(OFFLINE_ITEMS).then( x=>{
              var offline_items_list = JSON.parse(x);

              if (isConnected === true){
                  var json = httpPost('api/item', item)
                      .then(json => {
                          log('post item succeeded');
                          log(JSON.stringify(json));
                          online_items_list[json._id]=json;
                          log("online====="+JSON.stringify(online_items_list));
                          x = {};
                          x['2'] = '3';
                          log(JSON.stringify(x));
                          log(x);
                          log(x.toString());
                          AsyncStorage.setItem(ONLINE_ITEMS, JSON.stringify(online_items_list)).then(()=>{
                              var all = Object.assign({}, online_items_list, offline_items_list);
                              var arr = [];
                              for (var key in all) {
                                  arr.push(all[key]);
                              }
                              //setState(Object.assign({}, state, {items: arr}));
                              setState({ items: arr });
                              return json;
                          });
                      })
                      .catch(error => {
                          log('post item failed');
                      });
              }
                else{
                  offline_items_list[uuidv1()] = item;
                  log('offline===='+JSON.stringify(offline_items_list));
                  AsyncStorage.setItem(OFFLINE_ITEMS, JSON.stringify(offline_items_list));
                  var all = Object.assign({}, online_items_list, offline_items_list);
                  var arr = [];
                  for (var key in all) {
                      arr.push(all[key]);
                  }
                  //setState(Object.assign({}, state, {items: arr}));
                  setState({ items: arr });
              }

          });
      });
    //log(item);

  });

  log('render', isLoading);
  const value = { ...state, onSubmit };
  return (
    <CityIssueContext.Provider value={value}>
      {children}
    </CityIssueContext.Provider>
  );
};

/*
import React, { useCallback, useContext, useEffect } from 'react';
import { CityIssueContext } from './CityIssueContext';
import { getLogger, httpGet, httpPost } from '../core';
import { AuthContext } from '../auth/AuthContext';
import { AsyncStorage, NetInfo } from 'react-native';
const log = getLogger('CityIssueStore');

const ONLINE_ITEMS = 'ONLINE_ITEMS';
const OFFLINE_ITEMS = 'OFFLINE_ITEMS';
/*
AsyncStorage.setItem(ONLINE_ITEMS, JSON.stringify({}));
AsyncStorage.setItem(OFFLINE_ITEMS, JSON.stringify({}));
/*




const initialState = {
    isLoading: false,
    items: null,
    loadingError: null,
    isConnected: false
};

export const CityIssueStore = ({ children }) => {
    const [state, setState] = React.useState(initialState);
    const { isLoading, items, loadingError, isConnected } = state;
    const { token } = useContext(AuthContext);

    const ws = new WebSocket('ws://192.168.100.79:8080');

    useEffect(() => {
        NetInfo.getConnectionInfo().then((connectionInfo) => {
            console.log(
                'Initial, type: ' +
                connectionInfo.type
            );
            if (connectionInfo.type === 'wifi'){
                setState({isConnected:  true});
                connectionIsPresent();
            }
            else {
                setState({isConnected: false})
            }
        });

        function handleFirstConnectivityChange(connectionInfo) {
            console.log(
                'First change, type: ' +
                connectionInfo.type
            );
            if (connectionInfo.type === 'wifi'){
                setState({isConnected:  true});
                connectionIsPresent();
            }
            else {
                setState({isConnected: false})
            }

        }
        NetInfo.addEventListener('connectionChange', handleFirstConnectivityChange);

        return () => {
            console.log('CLOSING STORE')
        }
    }, [token]);

    const connectionIsPresent = () => {
        ws.onopen = evt =>{
            console.log('connected')
        };
        ws.onmessage = evt =>{
            console.log('update coming from ws');
            var cityIssue = JSON.parse(evt.data).data;

            AsyncStorage.getItem(ONLINE_ITEMS).then( x=>{
                var online_items_list = JSON.parse(x);
                AsyncStorage.getItem(OFFLINE_ITEMS).then( x=>{
                    var json = cityIssue;
                    var offline_items_list = JSON.parse(x);
                    console.log(online_items_list);
                    online_items_list[json._id] = json;
                    AsyncStorage.setItem(ONLINE_ITEMS, JSON.stringify(online_items_list));
                    var all = Object.assign({}, online_items_list, offline_items_list);
                    var arr = [];
                    for (var key in all) {
                        arr.push(all[key]);
                    }
                    setState({ items: arr });           });
            });
            console.log(JSON.parse(evt.data));
        };
        console.log('#############################################################################################')
        if (token && !loadingError && !isLoading) {
            log('load items started');
            setState({ isLoading: true, loadingError: null });
            httpGet('api/item')
                .then(json => {
                    log('load items succeeded');
                    var online_items_list = json;
                    //console.log(online_items_list);
                    AsyncStorage.getItem(OFFLINE_ITEMS).then(x=>{
                        var offline_items_list = JSON.parse(x);
                        for (var key in offline_items_list) {
                            var item = offline_items_list[key];
                            online_items_list[key] = item;
                            httpPost('api/item', item)
                                .then(json => {
                                    log('post item succeeded');
                                    log(JSON.stringify(json));
                                    console.log('%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%')
                                    return Promise.resolve(json);

                                })
                                .catch(error => {
                                    log('post item failed');
                                    return Promise.reject(error);
                                });
                        }
                        // poate nui bn
                        AsyncStorage.setItem(OFFLINE_ITEMS, JSON.stringify({}));
                        AsyncStorage.setItem(ONLINE_ITEMS, JSON.stringify(online_items_list));
                    });


                    setState({ isLoading: false, items: json });

                })
                .catch(loadingError => {
                    log('load items failed');
                    setState({ isLoading: false, loadingError })
                });
        }


    };

    const onSubmit = useCallback(async (item) => {
        log('post item started');
        log(item);
        return httpPost('api/item', item)
            .then(json => {
                log('post item succeeded');
                log(JSON.stringify(json));
                AsyncStorage.getItem(ONLINE_ITEMS).then( x=>{
                    var online_items_list = JSON.parse(x);
                    AsyncStorage.getItem(OFFLINE_ITEMS).then( x=>{
                        var offline_items_list = JSON.parse(x);
                        console.log(online_items_list);
                        online_items_list[json._id] = json;
                        AsyncStorage.setItem(ONLINE_ITEMS, JSON.stringify(online_items_list));
                        var all = Object.assign({}, online_items_list, offline_items_list);
                        var arr = [];
                        for (var key in all) {
                            arr.push(all[key]);
                        }
                        setState({ items: arr });
                        return Promise.resolve(json);
                    });
                });
            })
            .catch(error => {
                log('post item failed');
                return Promise.reject(error);
            });
    });

    log('render', isLoading);
    const value = { ...state, onSubmit };
    return (
        <CityIssueContext.Provider value={value}>
            {children}
        </CityIssueContext.Provider>
    );
};
*/

