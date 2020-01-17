export const getLogger = tag =>
  (message, ...args) => console.log(`${tag} ${message}`, args);
