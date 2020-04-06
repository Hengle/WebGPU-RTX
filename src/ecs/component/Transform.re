open StateType;

let create = state => {
  (
    state.transform.index,
    {
      ...state,
      transform: {
        ...state.transform,
        index: state.transform.index |> succ,
      },
    },
  );
};

let getTranslation = (transform, state) => {
  state.transform.translationMap |> ImmutableSparseMap.unsafeGet(transform);
};

let setTranslation = (transform, translation, state) => {
  ...state,
  transform: {
    ...state.transform,
    translationMap:
      state.transform.translationMap
      |> ImmutableSparseMap.set(transform, translation),
  },
};

let getRotation = (transform, state) => {
  state.transform.rotationMap |> ImmutableSparseMap.unsafeGet(transform);
};

let setRotation = (transform, rotation, state) => {
  ...state,
  transform: {
    ...state.transform,
    rotationMap:
      state.transform.rotationMap
      |> ImmutableSparseMap.set(transform, rotation),
  },
};

let getScale = (transform, state) => {
  state.transform.scaleMap |> ImmutableSparseMap.unsafeGet(transform);
};

let setScale = (transform, scale, state) => {
  ...state,
  transform: {
    ...state.transform,
    scaleMap:
      state.transform.scaleMap |> ImmutableSparseMap.set(transform, scale),
  },
};

let buildNormalMatrix = modelMatrix => {
  Matrix3.createEmptyMatrix3()
  |> Matrix4.invertTo3x3(modelMatrix)
  |> Matrix3.transposeSelf;
};

let buildModelMatrix = (transform, state) => {
  Matrix4.createIdentityMatrix4()
  |> Matrix4.fromTranslationRotationScale(
       getTranslation(transform, state),
       Quaternion.setFromEulerAngles(getRotation(transform, state)),
       getScale(transform, state),
     );
};
