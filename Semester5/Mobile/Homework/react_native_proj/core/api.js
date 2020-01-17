import {getLogger} from "./log";

const apiUrl = '192.168.122.1';

const httpApiUrl = `http://${apiUrl}:3000`;

export const wsApiUrl = `ws://${apiUrl}:8080`;

const defaultHeaders = {
  'Accept': 'application/json',
  'Content-Type': 'application/json'
};

let token;

export const setToken = value => {
  token = value;
};

const buildHeaders = () => {
  const headers = { ...defaultHeaders };
  if (token) {
    headers.Authorization = `Bearer ${token}`;
  }
  return headers;
};

const defaultIssue = { issue: [{ error: 'Unexpected error' }]};

const withErrorHandling = fetchPromise => fetchPromise
  .then(response => Promise.all([response.ok, response.json()]))
  .then(([responseOk, responseJson]) => {
    if (responseOk) {
      return responseJson;
    }
    const message = (responseJson || defaultIssue).issue
      .map(it => it.error)
      .join('\n');
    throw new Error(message);
  });

export const httpGet = path =>
  withErrorHandling(
    fetch(`${httpApiUrl}/${path}`, {
      method: 'GET',
      headers: buildHeaders(),
    })
  );

export const httpPost = (path, payload) =>
  withErrorHandling(
    fetch(`${httpApiUrl}/${path}`, {
      method: 'POST',
      body: JSON.stringify(payload),
      headers: buildHeaders(),
    })
  );
