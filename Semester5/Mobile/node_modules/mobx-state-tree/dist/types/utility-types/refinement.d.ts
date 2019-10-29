import { IAnyType } from "../../internal";
export declare function refinement<IT extends IAnyType>(name: string, type: IT, predicate: (snapshot: IT["CreationType"]) => boolean, message?: string | ((v: IT["CreationType"]) => string)): IT;
export declare function refinement<IT extends IAnyType>(type: IT, predicate: (snapshot: IT["CreationType"]) => boolean, message?: string | ((v: IT["CreationType"]) => string)): IT;
/**
 * Returns if a given value is a refinement type.
 *
 * @param type
 * @returns
 */
export declare function isRefinementType<IT extends IAnyType>(type: IT): type is IT;
