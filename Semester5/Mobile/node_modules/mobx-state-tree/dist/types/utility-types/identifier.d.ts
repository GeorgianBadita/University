import { ISimpleType } from "../../internal";
/**
 * `types.identifier` - Identifiers are used to make references, lifecycle events and reconciling works.
 * Inside a state tree, for each type can exist only one instance for each given identifier.
 * For example there couldn't be 2 instances of user with id 1. If you need more, consider using references.
 * Identifier can be used only as type property of a model.
 * This type accepts as parameter the value type of the identifier field that can be either string or number.
 *
 * Example:
 * ```ts
 *  const Todo = types.model("Todo", {
 *      id: types.identifier,
 *      title: types.string
 *  })
 * ```
 *
 * @returns
 */
export declare const identifier: ISimpleType<string>;
/**
 * `types.identifierNumber` - Similar to `types.identifier`. This one will serialize from / to a number when applying snapshots
 *
 * Example:
 * ```ts
 *  const Todo = types.model("Todo", {
 *      id: types.identifierNumber,
 *      title: types.string
 *  })
 * ```
 *
 * @returns
 */
export declare const identifierNumber: ISimpleType<number>;
/**
 * Returns if a given value represents an identifier type.
 *
 * @param type
 * @returns
 */
export declare function isIdentifierType<IT extends typeof identifier | typeof identifierNumber>(type: IT): type is IT;
/**
 * Valid types for identifiers.
 */
export declare type ReferenceIdentifier = string | number;
