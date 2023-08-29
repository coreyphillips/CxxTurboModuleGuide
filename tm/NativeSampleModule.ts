import type {TurboModule} from 'react-native/Libraries/TurboModule/RCTExport';
import {TurboModuleRegistry} from 'react-native';

export interface Spec extends TurboModule {
  readonly doFibExpensive: (n: number) => number;
  readonly hello: () => string;
  readonly hashString: (input: string) => string;
}

export default TurboModuleRegistry.getEnforcing<Spec>('NativeSampleModule');
