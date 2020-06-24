open StateType;

let create = () => {
  gameObject: {
    index: 0,
    transformMap: ImmutableSparseMap.createEmpty(),
    geometryMap: ImmutableSparseMap.createEmpty(),
    pbrMaterialMap: ImmutableSparseMap.createEmpty(),
    shaderMap: ImmutableSparseMap.createEmpty(),
    directionLightMap: ImmutableSparseMap.createEmpty(),
    transformAnimationMap: ImmutableSparseMap.createEmpty(),
    cameraViewMap: ImmutableSparseMap.createEmpty(),
    arcballCameraControllerMap: ImmutableSparseMap.createEmpty(),
  },

  transform: {
    index: 0,
    translationMap: ImmutableSparseMap.createEmpty(),
    rotationMap: ImmutableSparseMap.createEmpty(),
    scaleMap: ImmutableSparseMap.createEmpty(),
  },
  geometry: {
    index: 0,
    vertexDataMap: ImmutableSparseMap.createEmpty(),
    indexDataMap: ImmutableSparseMap.createEmpty(),
  },
  pbrMaterial: {
    index: 0,
    diffuseMap: ImmutableSparseMap.createEmpty(),
    metalnessMap: ImmutableSparseMap.createEmpty(),
    roughnessMap: ImmutableSparseMap.createEmpty(),
    specularMap: ImmutableSparseMap.createEmpty(),
  },
  // illumMap: ImmutableSparseMap.createEmpty(),
  // dissolveMap: ImmutableSparseMap.createEmpty(),
  directionLight: {
    index: 0,
    intensityMap: ImmutableSparseMap.createEmpty(),
    positionMap: ImmutableSparseMap.createEmpty(),
  },
  shader: {
    index: 0,
    hitGroupIndexMap: ImmutableSparseMap.createEmpty(),
  },
  transformAnimation: {
    index: 0,
    isAnimate: false,
    dynamicTransformMap: ImmutableSparseMap.createEmpty(),
  },
  arcballCameraController: {
    index: 0,
    isDrag: false,
    currentArcballCameraController: None,
    phiMap: ImmutableSparseMap.createEmpty(),
    thetaMap: ImmutableSparseMap.createEmpty(),
    targetMap: ImmutableSparseMap.createEmpty(),
    rotateSpeedMap: ImmutableSparseMap.createEmpty(),
    wheelSpeedMap: ImmutableSparseMap.createEmpty(),
    distanceMap: ImmutableSparseMap.createEmpty(),
  },
  cameraView: {
    index: 0,
    currentCameraView: None,
    cameraPositionMap: ImmutableSparseMap.createEmpty(),
    viewMatrixMap: ImmutableSparseMap.createEmpty(),
    projectionMatrixMap: ImmutableSparseMap.createEmpty(),
  },
  pass: {
    accumulatedFrameIndex: 0,
    jitterArr: [||],
    gbufferPassData: {
      lastModelMatrixMap: ImmutableSparseMap.createEmpty(),
      lastViewProjectionMatrix: None,
      pipeline: None,
      depthTextureView: None,
      staticBindGroupDataArr: [||],
      dynamicBindGroupDataArr: [||],
      renderGameObjectArr: [||],
      vertexAndIndexBufferMap: ImmutableSparseMap.createEmpty(),
      indexCountMap: ImmutableSparseMap.createEmpty(),
    },
    rayTracingPassData: {
      pipeline: None,
      staticBindGroupDataArr: [||],
    },
    // indirectLightSpecularSampleCount: 1,
    preprocessPassData: {
      pipeline: None,
      staticBindGroupDataArr: [||],
    },
    regressionPassData: {
      pipeline: None,
      staticBindGroupDataArr: [||],
    },
    postprocessPassData: {
      pipeline: None,
      staticBindGroupDataArr: [||],
    },
    taaPassData: {
      isFirstFrame: true,
      firstFramePipeline: None,
      firstFrameStaticBindGroupDataArr: [||],
      otherFramePipeline: None,
      otherFrameStaticBindGroupDataArr: [||],
    },
    accumulationPassData: {
      pipeline: None,
      staticBindGroupData: None,
      accumFrameCount: 1,
      accumFrameCountForDenoise: 100,
      lastViewMatrix: None,
    },
    uniformBufferDataMap: ImmutableHashMap.createEmpty(),
    storageBufferDataMap: ImmutableHashMap.createEmpty(),
    float32StorageBufferTypeArrayDataMap: ImmutableHashMap.createEmpty(),
    textureViewMap: ImmutableHashMap.createEmpty(),
  },
  rayTracing: {
    accelerationContainer: {
      geometryContainers: None,
      instanceContainer: None,
      instanceBufferArrayBuffer: None,
      instanceBuffer: None,
    },
  },
  director: {
    time: 0.0,
    frameIndex: 0,
    initFuncArr: [||],
    updateFuncArr: [||],
    passFuncDataArr: [||],
  },
};
